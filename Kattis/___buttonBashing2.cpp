#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct times{
    int value = 0; //The actual number of time this object represents
    int distance = 0; //The number of button pushes to get to this time
}; 

int main(){
    int numCases, difference;
    int numButtons, desiredTime, buttonTimes;
    vector <int> buttons;
    vector <int>::iterator itr;
    queue<times> BFS; // this is queue for BFS --> Hypothetically This will the times explored;
    times front, temp;
    bool passed_desired_time;

    cin>>numCases;
    for(int x = 0 ; x < numCases; x++){
        BFS = queue<times>();
        buttons.clear();
        passed_desired_time = false;
        cin>>numButtons>>desiredTime;
        for(int y =0; y < numButtons; y++ ){
            cin>>buttonTimes;
            if(buttonTimes != 0)
                buttons.push_back(buttonTimes);
        }
        BFS.push(times{0,0});
        while(!BFS.empty()){ //Finds the number of button presses to either reach or exceed the desired time
            front = BFS.front();
            BFS.pop();
            if(front.value == desiredTime)
                break;
            for(itr = buttons.begin(); itr<buttons.end(); itr++){
                temp = {front.value+(*itr), front.distance+1};
                if(!passed_desired_time && *itr < 0)
                    continue;
                else if(!passed_desired_time && temp.value >= desiredTime){
                    BFS = queue<times>();
                    BFS.push(temp);
                    passed_desired_time = true;
                }
                else if (front.value-desiredTime > temp.value-desiredTime) //If getting closer to desired time, then push 
                    BFS.push(temp);
            }
            cout<<front.distance<<" "<<front.value<<endl;
        }
    }
    return 0;
}