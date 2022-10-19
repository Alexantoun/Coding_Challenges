#include <iostream>
using namespace std;

int main(){
    double engMiles;
    cin >> engMiles;
    int answer = engMiles * (5280.0 / 4854.0) * 1000.0 + 0.5;
    cout<<answer<<endl;
    return 0;
}