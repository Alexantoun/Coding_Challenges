#include <iostream>
#include <string>
using namespace std;
int main()
{
    int guess = 500;
    int high = 1001, low = 1;
    string response;
    for(int i=1;i<=10;i++)
    {
    cout<<guess<<endl<<flush;
    cin>>response;
    if (response == "lower")
    {
        high = guess;
        guess =((high+low)/2);
    }
    else if (response == "higher")
    {
        low = guess;
        guess =(high+low)/2;
    }
    else if (response == "correct")
        break;
    }
    return 0;
}
