#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

struct values{
    int value = 0, num_fours = 0;
    string ops= "";
};


void outString(const string& output){
    for(int i = 0; i < 3; i++)
        cout<<"4 "<< output[i]<<" ";

    cout<<"4 = ";
}

//Use BFS to find the results of the + - / * operations 

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int target,test_cases;
    queue<values> results;
    unordered_map<int, string> solutions;
    unordered_map<int, string>::iterator itr;
    values curr;

    cin>>test_cases;
    while(test_cases--){
        cin>>target;
        curr ={0,0,""};
        results.push(values{0,0});
        while(!results.empty()){//Let i represent the number of fours used
            curr = results.front();
            results.pop();
            if(curr.num_fours == 4){
                solutions[curr.value] = curr.ops;
            }
            else if(curr.num_fours < 4){
                results.push(values{curr.value + (4+4), curr.num_fours+1, curr.ops+"+"}); 
                results.push(values{curr.value + (4/4), curr.num_fours+1, curr.ops+"/"});
                results.push(values{curr.value + (4*4), curr.num_fours+1, curr.ops+"*"});
                results.push(values{curr.value + (4-4), curr.num_fours+1, curr.ops+"-"});
            }
            else
                break;
        }
        //Final push into map
        // while(!results.empty()){// the map will let you hunt down the desired value, and find the operations occured in O(1) time
        //     curr = results.front();
        //     results.pop();
            
        // }
        // cout<<"Printing results: "<<endl;
        // for(itr = solutions.begin(); itr!= solutions.end(); itr++)
        //     cout<<itr->first<<" from " << itr->second<<endl;
        itr = solutions.find(target);
        if(itr == solutions.end())
            cout<<"no solution"<<endl;
        else{
            outString(itr->second);
            cout<<target<<endl;
        }
    }
    return 0;
}