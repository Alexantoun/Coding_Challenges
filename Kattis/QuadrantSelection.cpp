#include <iostream>
using namespace std;

int main ()
{
    int x, y;
    cin>>x>>y;
    if(x*y > 0)
    {
        if (x>0)
            cout<<"1"<<endl;
        else if (x<0)
            cout<<"3"<<endl;
    }
    else if (x*y < 0)
    {
        if (x>0)
            cout<<"4"<<endl;
        else if (x<0)
            cout<<"2"<<endl;
    }
    return 0;
}
