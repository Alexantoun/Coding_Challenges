#include <iostream>
#include <cmath>
using namespace std;

//Given an integer, return the closest integer >0 that ends with '99'
int main(){
    int in, numDigits;
    int upper, lower;
    cin >> in;
    numDigits = log10(in);
    //Using implicit casting to replace last to digits with 00, and then making them 99
    upper = (in/100) * 100 + 99;
    lower = (in/100) * 100 - 1;
    //If the lower value is less than 0, use the upper. Otherwise, use the closest one
    if(lower < 0 || (upper - in <= in - lower)  )
        cout<<upper<<endl;
    else
        cout<<lower<<endl;
    
    return 0;
}