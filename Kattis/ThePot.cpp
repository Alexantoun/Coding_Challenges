#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    int numCases, power;
    long int outPut =0;
    cin>>numCases;
    int pVal[numCases];
    for (int i=0;i<numCases;i++)
    {
        cin>>pVal[i];
        power=pVal[i]%10;
        pVal[i]/=10;
        pVal[i]=pow(pVal[i],power);
        outPut+=pVal[i];
    }
    cout<<outPut<<endl;
    return 0;
}