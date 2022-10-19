#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int battles, victories=0;
    cin>>battles;
    char combo[2001];
    cin.ignore(256,'\n');
    for(int i=0;i<battles;i++)
    {
        cin.getline(combo,2000,'\n');
        if (strstr(combo,"CD")==NULL)
            victories++;
    }
    cout<<victories<<endl;
    return 0;
}