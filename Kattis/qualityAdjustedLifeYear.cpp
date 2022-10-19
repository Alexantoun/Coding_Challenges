#include <iostream>
using namespace std;

int main(){

    int N;
    double q, y, sumQ = 0;

    cin>>N;

    for (int x = 0; x<N; x++){
        cin>>q>>y;
        sumQ += q*y;
    }
    cout<<sumQ<<endl;
    return 0;
}