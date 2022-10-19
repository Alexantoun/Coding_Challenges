#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Syntax candy
enum units { thou, inch, foot, yard, chain, furlong, mile, league };
long conversions[8];

//Initializes array
void initem(long conversions[]){
    conversions[thou] = 1;
    conversions[inch] = 1000;
    conversions[foot] = 12*(conversions[inch]);
    conversions[yard] = 3*(conversions[foot]);
    conversions[chain] = 22*(conversions[yard]);
    conversions[furlong] = 10*(conversions[chain]);
    conversions[mile] = 8*(conversions[furlong]); 
    conversions[league] = 3*(conversions[mile]);
}

//Takes the name of unit as string and returns value of unit thous
double getValue(string phrase){
    if (phrase[0] =='t')
        return conversions[thou];
    else if(phrase[0] == 'i')
        return conversions[inch];
    else if(phrase[0] == 'f'){
        if(phrase[1] == 't' || phrase[1]=='o')
            return conversions[foot];
        else
            return conversions[furlong];
    }
    else if(phrase[0] == 'y')
        return conversions[yard];
    else if(phrase[0] == 'c')
        return conversions[chain];
    else if(phrase[0] =='m')
        return conversions[mile];
    else if(phrase[0] == 'l')
        return conversions[league];
    else    
        cout<<"Failure in getValue()"<<endl;
    return -1;
}

double equation(int value, string numerator, string denominator){
    // cout<<"value in thous is: "<<value*(getValue(numerator))<<endl;
    // cout<<"Denominator in thous is: "<<value*(getValue(denominator))<<endl;
    return value*(getValue(numerator) / getValue(denominator));
}

int main(){
    initem(conversions);

    // for(int x =0; x< 8; x++)
    //     cout<<conversions[x]<<endl;

    int number = 0;
    string numerator, denominator, burn;

    cin>>number>>numerator>>burn>>denominator ;
    cout<<setprecision(10)<<equation(number, numerator, denominator)<<endl;


    return 0;
}