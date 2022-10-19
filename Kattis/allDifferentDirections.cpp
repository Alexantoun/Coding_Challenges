#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const double pi = 3.14159265;

double toRadians(const double& deg){
    return (pi*deg)/180;
}

//Stores the average of array into the last index, and returns that value
double averageValue(double values[], const int& numPeople){
    double sum = 0;
    double largest = 0;

    for(int x = 0; x<numPeople; x++)
        sum += values[x];

    values[numPeople] = sum/numPeople;
    return values[numPeople];
}
//Finds difference between the average value and the largest value
double largestError(double x[], double y[], const int& numPeople){
    double x2 = x[numPeople];
    double y2 = y[numPeople];
    double greatestDistance = 0;
    double error;
    for(int person = 0; person < numPeople; person++){
        error = sqrt( pow(x2-x[person], 2) + pow(y2-y[person], 2) );
        if(error > greatestDistance){
            greatestDistance = error;
            // cout<<"\nGreatest Distance = "<<greatestDistance;
        }
    }
    return greatestDistance;
}

int main(){
    //max of 100 test cases. 1st input is number of people asked for directions
    int numPeople;
    double *endpointsX, *endpointsY;
    double angle, input; //This will hold values that can be used in calculations from later
    string instr;
    while(cin>>numPeople){
        //Dynamically allocate space for each persons set of directions
        endpointsX = new double[numPeople + 1];//Last element will hold average;
        endpointsY = new double[numPeople + 1];
        for(int person = 0; person < numPeople; person++){ //Asking the next <numPeople> directions
            cin>>endpointsX[person]>>endpointsY[person];
            while(cin.peek() != '\n'){
                cin>>instr;
                // cout<<"In switch"<<endl;
                switch (instr[0]){
                    case 'w': // A distance is input, and you need to calc the x and y components
                        cin>>input;
                        while(angle >= 360)
                            angle -= 360;
                        while(angle < 0) //Incase person wants you to spin around 
                            angle += 360; //If angle is negative, adding to 360 is subtracting from 360
                        //Pythagorean method of finding horizontal (x) and vertical (y) components of movement
                        //Using hypotenuse (distance walked) and direction (angle)
                        endpointsX[person] +=  input * cos(toRadians(angle));
                        endpointsY[person] +=  input * sin(toRadians(angle));
                        break;

                    case 't': //An angle in deg is given to turn FROM your current angle -> not from 0
                        cin>>input;
                        angle += input;
                        break;

                    case 's': //An angle is given and that can be used for following calculations
                        cin>>angle;
                        break;
                    default:
                        cerr<<"Erroneous input"<<endl;
                        break;
                }
            }
        }
        if(numPeople > 0){
            cout<<fixed<<setprecision(5)<<averageValue(endpointsX, numPeople)<<" "<<averageValue(endpointsY, numPeople)<<" "<<largestError(endpointsX, endpointsY, numPeople) <<endl;
            delete[] endpointsX;
            delete[] endpointsY;
        }
    }
    return 0;
}