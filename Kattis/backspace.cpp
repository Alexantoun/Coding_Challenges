/*
    Store a string, if the '<' char is encountered, delete the last character input. 
    at EOF output the string in order of arrival
*/
#include <deque>
#include <iostream>
using namespace std;

int main(){
    char input;
    deque<char> keepString;
    while(cin>>input)
        (input == '<')? keepString.pop_back() : keepString.push_back(input); //If char is '<' then delete last char, else add to back of queue
    
    while(!keepString.empty()){ //Output input in order of arrival
        cout<<keepString.front();
        keepString.pop_front();
    }
    return 0;
}