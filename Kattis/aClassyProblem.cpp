#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

const string end_case_delimeter = "==============================";

struct people{
    string name;
    long _class = 0;
};

//specify how comparison works for people struct
auto it=[](people a, people b){
    //comparison logic, Does object 'a' and object 'b' need to be swapped?
    if (a._class > b._class)
        return false;
    else if (a._class < b._class)
        return true;
    else{
        if ((a.name).compare(b.name) < 0)
            return false;
        else    
            return true;
    }
}; 

//reads the hyphon seperated descriptors of class
void establishClass(people& person){
    long multiplier = 1;
    char line [200];
    cin>>line;
    //Upper has the highest, followed by middle followed by lower
    char *token = strtok(line, "-"); //Seperate the list by hyphons
    while(token != NULL){ //This will grab a class value, then increment to next power of ten and take another another class value over and over
        switch (token[0]){
            case 'u':
                person._class += (3*multiplier);
                break;
            case 'm':
                person._class += (2*multiplier);
                break;
            case 'l':
                person._class += (1*multiplier);
                break;
        }
        token = strtok(NULL, "-");
        multiplier*= 10;
    }
    //unsecified standings of parent social-class are assumed to be 'middle' - aka, 2
    while(person._class / 10000000000 == 0){
        person._class*= 10;
        person._class+= 2;
    }
}

int main(){
    int testCases, numPeople;
    people *somebody;
    cin >> testCases;
    priority_queue<people, vector<people>, decltype(it)> group(it); //make the priority queue use the lamda function
    for(int x = 0; x < testCases; x++){
        cin.ignore(256,'\n');
        cin>>numPeople;
        for(int person = 0; person < numPeople; person++){
            somebody = new people;
            cin.ignore(256,'\n');
            getline(cin, somebody->name, ':');
            establishClass(*somebody);
            group.push(*somebody);
        }
        while(!group.empty()){ //I couldnt figure out how to pass the priority queue to another function, else this would me printQueue() call
            cout<<group.top().name<<endl;
            group.pop();
        }
        group.empty();
        delete somebody;
        cout<<end_case_delimeter<<endl;
    }
}
