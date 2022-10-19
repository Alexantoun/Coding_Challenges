#include<iostream>
using namespace std;

int main()
{
    //int numbers[10];
    int answers[10], input;
    for (int i=0;i<10;i++)
    {
        //cin>>numbers[i];
        cin>>input;
        answers[i]=input%42;
    }
    int distinct=1;
    for (int i=0;i<10;i++)
    {
       for (int j = 0; j < i; j++)
       {
           if (answers[i]==answers[j] && i!=j)
                break;
           else if (j==i-1)
                distinct++;
       }
    }
    cout<<distinct<<endl;
    return 0;
}