#include <iostream>
#include <iomanip>
using namespace std;

// Types of characters: whitespace characters, lowercase letters, uppercase letters, and symbols.
// symbols == not the other classes
int main(){
    char input;
    int numLowerCase=0, numUpperCase=0, numSymbolic=0, numSpaces=0;
    int ascii;
    double totalChars = 0;
    while(cin>>input){
        ascii = int(input);
        if(ascii >= 97 && ascii<=122) //Is lowercase?
            numLowerCase++;
        else if(ascii >= 65 && ascii <= 90) // Is uppercase?
            numUpperCase++;
        else if(ascii == '_' ) // Is a whitespace (in this challenge whitespaces represented by '_')
            numSpaces++;
        else    
            numSymbolic++;
        totalChars+=1;
    }
    // Max error allowed is 10^-6
    cout<<setprecision(7)<< (numSpaces/totalChars) << endl << (numLowerCase/totalChars) <<endl<< (numUpperCase/totalChars) << endl << (numSymbolic/totalChars)<< endl;
    return 0;
}
