#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    unordered_map<string, int> words_occur;
    unordered_map<string, int>::const_iterator itr;

    string input;
    bool repeated_word = false;

    while(cin>>input){
        itr = words_occur.find(input);
        if(itr == words_occur.end()){
            // COUT<<"Adding: "<<input<<endl;
            words_occur.insert({input, 0});
        }
        else{
            repeated_word = true;
            break;
        }
    }
    if(repeated_word)
        cout<<"no"<<endl;
    else
        cout<<"yes"<<endl;
    return 0;
}