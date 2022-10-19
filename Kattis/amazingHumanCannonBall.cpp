#include <iostream>
#include <cmath>
using namespace std;

const double g = 9.81;
const double pi =  3.14159;

int main (){
    int numCases;
    cin>> numCases;
    //Values are given in the below order.
    //h1 is the bottom of hole, h2 is the top of hole
    double vel0, theta,x1, h1, h2;
    double t, y; //We determine these ones

    for(int x = 0; x<numCases; x++){
        cin>>vel0>>theta>> x1>> h1>> h2;
        theta = (theta*pi)/180; //cmath trig functions require radians

        //To pass safely, there has to be a vertical safety margin of  m both below and above the point where the ball’s trajectory crosses the centerline of the wall.
        t = x1/(vel0*cos(theta));//Formula is given with a little algebra
        
        //To find height at time t
        y = (vel0*t*sin(theta));
        y -= g * t * t * 0.5  ;

        // cout<<y<<endl;
        // cout<<"min height: "<<h1+1<<" max height: "<<h2-1<<endl;
        if(y-1 >= h1 && y+1 <= h2)
            cout<<"Safe"<<endl;
        else    
            cout<<"Not Safe"<<endl;
    }
    return 0;
}
