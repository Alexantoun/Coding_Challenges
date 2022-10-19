#include <iostream>
using namespace std;

int main ()
{
    int caseNum;
    cin>>caseNum;
    while (caseNum!=-1)
    {
        int mph1=0, t1 =0, t2=0, temp=0;
        int distance=0;;
        for(int i=0;i<caseNum;i++)
        {
            cin>>mph1>>t2;
            t1=t2-temp;
            /*output for debuging: cout<<"Test t1 = "<<t1<<endl;*/
            distance+= mph1*t1;
            temp=t2;
        }
        cout<<distance<<" miles"<<endl;
        cin>>caseNum;
    }
        return 0;
}