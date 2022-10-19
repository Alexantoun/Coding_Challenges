#include <iostream>
using namespace std;

//Returns the largest number
int maxNum(int& num1,int& num2){
    if(num1 >= num2)
        return num1;
    return num2;
}
int main(){
    int left = 0;
    int vacationDays, lowestStartDay = 0, maxTemp = 999999;
    int *temps;

    cin>> vacationDays;
    temps = new int[vacationDays];
    //Read first 3 values and find the largest temp 
    cin>>temps[0]>>temps[1]>>temps[2];
    maxTemp = maxNum(temps[left], temps[left+2]);
    //For the rest we comapre the largest of the two hiking days (left & left+2)
    for(int i = 3; i < vacationDays; i++){
        left++;
        cin>>temps[i];
        if(maxNum(temps[left], temps[left+2]) < maxTemp){ //If lower, then we store these days instead
            lowestStartDay = left;
            maxTemp = maxNum(temps[left], temps[left+2]);
        }
    }

    //Return the day to leave for the trip, and the largest temp encountered 
    cout<<endl<<lowestStartDay+1;
    (temps[lowestStartDay] >= temps[lowestStartDay+2])? cout<<" "<<temps[lowestStartDay] :  cout<<" "<<temps[lowestStartDay+2];
    delete [] temps;

    return 0;
}