#include <iostream>
#include <queue>
#include <vector>
using namespace std;
    /*use BFS let each layer represent the number times a button is pushed -> bp
        then the nodes @ each layer will represent the sum of values each button thats been pushed is
        BFS until desired value is reached.
            You're then pushing to the BFS_Queue the running sums of button pushes

        If you can't reach the desired value exactly, output the minimum number of button presses required to exceed
        the desired time, and output the number of excess seconds -> i.e desiredTime - sumOfButtonPushes 
    */

struct times{
    int value = 0; //The actual number of time this object represents
    int distance = 0; //The number of button pushes to get to this time
}; 

int main(){
    int numCases, bp, timer;
    int numButtons, desiredTime, buttonTimes;
    bool found = false;
    vector <int> Buttons;
    vector <int> negButtons;
    vector <int>::iterator itr;
    priority_queue<int> bt; // This will hold the button times available. Im just going to slap this into the queue below
    queue<times> BFS; // this is queue for BFS --> Hypothetically This will the times explored;
    times front;

    cin>>numCases;
    for(int x =0 ; x< numCases; x++){
        cin>>numButtons>>desiredTime;
        bp = 0;
        for(int y =0; y < numButtons; y++ ){
            cin>>buttonTimes;
            Buttons.push_back(buttonTimes);
            if(buttonTimes < 0)
                negButtons.push_back(buttonTimes);
        }
    }
    found = true;
    BFS.push(times{0,0});
    while(!BFS.empty()){ //Finds the number of button presses to either reach or exceed the desired time
        front = BFS.front();
        BFS.pop();
        if(front.value >= desiredTime)
            break;
        for(itr = Buttons.begin(); itr<Buttons.end(); itr++)
            BFS.push(times{front.value+*itr, front.distance+1 });
    }

    //Now front of the queue will hold the first value to be >= desired, but the next 'Buttons.size()'-elements could also be candidates, so keep smallest of those
    times smallestValid = front;//Assume front value is the smallest valid
    for(int x = 0; x < Buttons.size(); x++){
        front = BFS.front();
        if(smallestValid.value > front.value)
            smallestValid = front;
        BFS.pop();
    }
            
    if(smallestValid.value > desiredTime){
        front = smallestValid;
        queue<times> backwards;
        backwards.push(front); //Push the front value, try go backwards with the negative buttons
        while(!backwards.empty()){
            front = backwards.front();
            if(front.value == desiredTime)
                break;
            for(itr = negButtons.begin(); itr<negButtons.end(); itr++)
                if(front.value + *itr >= desiredTime) //Else, we don't want to waste time considering it
                    backwards.push(times{front.value+ *itr, front.distance+1}); //We add itr.value to front value as the itr.value are negatives, so we're subtracting
        }
    }
    //Research subset sum problem
    return 0;
}