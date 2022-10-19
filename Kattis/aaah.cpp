#include <iostream>
using namespace std;

int main(){
    char input = 0;
    int numA = 0;
    cin>>input;

    //count the number of A's
    while(input != 'h') {
        numA++;
        cin>>input;
    }
    
    //Subtract from the number of A's, once its below zero, then "no".
    cin>>input;
    while(input != 'h') {
        numA--;
        if(numA < 0){
            cout<<"no"<<endl;
            return 0;
        }
        cin>>input;
    }
    //@ this point, you can go
    cout<<"go"<<endl;
    return 0;

}