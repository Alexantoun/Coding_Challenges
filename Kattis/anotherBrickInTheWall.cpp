#include <iostream>

using namespace std;

int main(){
    int h,w,n;
    int sum, input;
    cin >>h>>w>>n;
    //Bricks should always sum to the width of the wall
    for(int height = 0; height < h; height++){
        sum = 0;
        while(sum < w){
            cin>> input;
            sum += input;
        }
        if(sum != w)
            break;
    }
    (sum == w)? cout<<"YES"<<endl : cout<<"NO"<<endl;
    return 0;
}