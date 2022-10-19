#include <iostream>
#include <string>

using namespace std;
int main(){
    string inputString;
    cin>>inputString;

    cout<<inputString[0]; //As the first char can't equal the non existant char before it, its safe to print
    for(int x = 1; x < inputString.length(); x++)
        if(inputString[x] != inputString[x-1])
            cout<<inputString[x];

    return 0;
}
