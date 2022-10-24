#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct times{
    int value = 0; //The actual number of time this object represents
    int distance = 0; //The number of button pushes to get to this time
}; 

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int numCases, numButtons, desiredTime, buttonTimes;
    vector <int> posButtons, negButtons;
    vector <int>::iterator itr;
    queue<times> BFS, backwards; // this is queue for BFS --> Hypothetically This will the times explored;
    times front;
    bool desired_found;

    cin>>numCases;
    for(int x =0 ; x< numCases; x++){
        BFS = queue<times>();
        backwards = queue<times>(); 
        solution = queue<times>();

        negButtons.clear();
        posButtons.clear();
        desired_found = false;
        cin>>numButtons>>desiredTime;
        for(int y =0; y < numButtons; y++ ){
            cin>>buttonTimes;
            if(buttonTimes > 0)
                posButtons.push_back(buttonTimes);
            if(buttonTimes < 0)
                negButtons.push_back(buttonTimes);
        }

        BFS.push(times{0,0});
        while(!BFS.empty()){ //Finds the number of button presses to either reach or exceed the desired time
            front = BFS.front();
            BFS.pop();
            if(front.value >= desiredTime)
                break;
            for(itr = posButtons.begin(); itr<posButtons.end(); itr++){
                times temp = {front.value+*itr, front.distance+1};
                if(!desired_found && temp.value > desiredTime)
                    BFS = queue<times>();
                BFS.push(temp);
            }
        }
        times smallestValid = front;
        if(smallestValid.value > desiredTime){
            front = smallestValid;
            backwards.push(front); //Push the front value, try go backwards with the negative buttons
            while(!backwards.empty()){
                front = backwards.front();
                backwards.pop();
                if(front.value == desiredTime)
                    break;
                for(itr = negButtons.begin(); itr<negButtons.end(); itr++) //Go through all the negative buttons and add their values to front time
                    if(front.value + *itr >= desiredTime) //If time is still >= desired, add it. Else, we don't want to waste time considering it
                        backwards.push(times{front.value+ *itr, front.distance+1}); //We add itr.value to front value as the itr.value are negatives, so we're subtracting
            }
        } //Now the front value will be the contain the number of button pushes required.
    
        if(front.value == desiredTime)
            cout<<front.distance<<" "<<0<<endl;
        else
            cout<<smallestValid.distance<<" "<<smallestValid.value - desiredTime<<endl;
    }
    return 0;
}