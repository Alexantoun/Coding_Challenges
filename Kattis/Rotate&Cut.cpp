#include <iostream>
#include <cstring>
using namespace std;
struct herp
{
    char line1[2001];
    int foldNum;
};
int main()
{
    int cases, trim;
    cin>>cases;
    herp foldAndLine[cases];

    for(int i=0;i<cases;i++)
        cin>>foldAndLine[i].foldNum>>foldAndLine[i].line1;
    for(int i=0;i<cases;i++)
    {
        for (int g=0;g<=22 && g<foldAndLine[i].foldNum;g++)
        {
            
            if (g%2!=0)
            {
                trim=(strlen(foldAndLine[i].line1))/4;
                if(trim>0)
                    foldAndLine[i].line1[strlen(foldAndLine[i].line1)-trim]='\0';
            }
            else if(g%2==0)
            {
                trim=(strlen(foldAndLine[i].line1))/4;
                for(int q=0;q<strlen(foldAndLine[i].line1);q++)
                    foldAndLine[i].line1[q]=foldAndLine[i].line1[q+trim];
            }
        }
        cout<<foldAndLine[i].line1<<endl<<endl;
    }
    return 0;
}