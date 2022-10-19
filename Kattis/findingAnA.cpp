#include <iostream>
using namespace std;

int main(){
    char outStr [1000] = {'\0'};
    char in = ' ';
    do{
        cin >> in;
    }while(in != 'a');
    
    cin >> outStr;
    cout<<in<<outStr<<endl;
}