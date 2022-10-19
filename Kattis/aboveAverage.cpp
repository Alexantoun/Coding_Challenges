#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

int main(){
    int testCases, N, sum;
    int studScore, studentsAbove;
    double average;
    cin >> testCases;
    priority_queue<int> scores;

    for (int x = 0; x < testCases; x++){
        cin>>N;
        scores = {};
        sum = 0;
        for(int student = 0; student < N; student++){
            cin>>studScore;
            sum += studScore;
            scores.push(studScore);
        }
        average = (sum*1.0)/(N*1.0);
        // cout<<"Average: "<<average<<endl;
        studentsAbove = 0;
        while(scores.top() > average){
            studentsAbove++;
            scores.pop();
        }
        cout<<fixed<<setprecision(3)<<(studentsAbove*1.0/N)*100<<'%'<<endl;
    }
        
    return 0;
}