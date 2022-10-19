#include <iostream>
#include <queue>
using namespace std;
int main(){
    long long in1, in2;
    queue<long long> results;
    while(cin>>in1>>in2) //Read until eof and store results into queue --> FiFo
        (in1 >= in2) ? results.push(in1 - in2) : results.push(in2 - in1);
    while(!results.empty()){ //Output queue
        cout << results.front()<<endl;
        results.pop();
    }
    return 0;
}
