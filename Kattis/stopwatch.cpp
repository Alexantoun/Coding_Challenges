#include <iostream>
using namespace std;

int main(){
    int numPresses = 0, sum=0;
    // Time watch started, and watch stopped respectivley
    int clockOn = 0, clockOff = 0;
    int x = 0;
    cin >> numPresses >> clockOn; // First push is to start watch
    x++;
    for ( x = x; x < numPresses; x++){
        if(x % 2 == 1){ // when watch is stopped...
            cin >> clockOff;
            sum += clockOff - clockOn; // running time for 1 round = difference between time watch was started and stopped
        }
        else
            cin >> clockOn; //Watch is started again
    }
    if(x%2 == 0) //x is incremented just before loop, so the stoppage occures at a different mod value
        cout<<sum<<endl;
    else    
        cout<<"still running"<<endl;

    return 0;
}