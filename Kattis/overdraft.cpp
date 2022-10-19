#include <iostream> 

using namespace std;

int main(){

    int testCases, lowest = 0, in, sum = 0;
    cin >> testCases;

    for(int x = 0 ; x< testCases; x++){
        cin >> in;
        sum += in;
        if(sum < lowest)
            lowest = sum; //We only need to make sure we can cover the lowest value
    }
    (lowest >= 0)? cout<<0<<endl : cout<<(lowest*-1)<<endl;
    return 0;
}