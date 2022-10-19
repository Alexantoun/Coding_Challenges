#include <iostream>
using namespace std;

int main(){
    int statues;
    cin>>statues;
    
    int printers = 1;
    int numPrinted = 0, days = 0;

    // time = numStatues / numPrinters the more printers, the less time it takes
    // Notice: That absolute min is when numPrinters is @ max possible
    while(numPrinted < statues){
        //Make more printers if the number of statues made
        // in one day is less than what is needed
        if((statues - numPrinted) > printers) { 
            printers += printers;
            days++;
        }
        else{
            days++;
            numPrinted += printers; //Every printer can print 1 statues per day
        }
    }
    cout<<days<<endl;
    return 0;
}