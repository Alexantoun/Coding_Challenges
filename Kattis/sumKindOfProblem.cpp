#include <iostream>
using namespace std;

int main(){
    int P, K, N;
    int sum = 0;
    cin>>P;
    
    for (int x = 0; x < P; x++){
        cin>> K >> N;
        //Sum of the first N Positive integers
        sum = 0;
        for(int x = 0; x<=N; x++)
            sum+=x;
        cout<<endl<<K<<" "<< sum;

        //Sum of the first N odd integers
        sum = 0;
        for(int x = 1; x<=(N*2); x+=2)
            sum+=x;
        cout<<" "<< sum;
        
        //Sum of the first N Even integers
        sum = 0;
        for(int x = 0; x<=(N*2); x+=2)
            sum+=x;
        cout<<" "<< sum << endl;
    }
    return 0;
}