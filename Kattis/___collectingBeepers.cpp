#include <iostream>
#include <vector> //To make passing matrix of unkown sizes easier

using namespace std;

int main(){
    int numScenarios, row, col;
    int posy, posx, numBeeps;
    //Input number of scenarios
    cin>> numScenarios;
    for(int round = 0; round < numScenarios; round++){
        //Input W x H sizes of matrix
        cin>>row>>col;
        vector<vector<int>> matrix(row , vector<int> (col, 0)); 
        //Karels starting position
        cin>>posy>>posx;
        matrix[posy][posx] = 10;
        // Number of beepers to find
        cin>>numBeeps;
        for(int x = 0; x < numBeeps; x++){
            //For all beepers, there's two ints that indicate starting position of beepers
            cin>>posy>>posx;
            matrix[posy][posx] = 2;
        }
    }
    //output the minimal number of moves to get every beeper
    return 0;
}