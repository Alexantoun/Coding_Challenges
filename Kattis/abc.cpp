#include <iostream>
using namespace std;

enum  {A,B,C};

int main(){
    int input[3], a,b,c;
    int temp;
    cin>>input[0]>>input[1]>>input[2];

    for(int x = 0; x<3; x++){
        for(int y = 0; y<3; y++)
            if (input[x] < input[y]){
                temp = input[x];
                input[x] = input[y];
                input[y] = temp;
            }
    }

    char order[3];
    cin>>order[0]>>order[1]>>order[2];
    for(int x = 0; x<3; x++){
        switch (order[x]){
            case 'A':
                cout<<input[A]<<' ';
                break;
            case 'B':
                cout<<input[B]<<' ';
                break;
            case 'C':
                cout<<input[C]<<' ';
                break;
            default:
                cerr<<"Erroneous input"<<endl;
        }
    }
    cout<<endl;
    return 0;
}