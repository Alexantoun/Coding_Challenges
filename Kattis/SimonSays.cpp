#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int rounds;
    cin>>rounds;
    string simons[rounds];
    string burn;
    char says[11]="Simon says";
    getline(cin,burn);
    for (int i=0;i<rounds;i++)
    {
        getline(cin,simons[i]);
    }
    
    for(int i=0;i<rounds;i++)
    {
        char simTest[11];
        simons[i].copy(simTest,10,0);
        if(strcmp(simTest,says)==0)
        {
            simons[i].erase(0,11);
            cout<<simons[i]<<endl;
        }
    }
    return 0;
}