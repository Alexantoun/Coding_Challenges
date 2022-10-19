#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> affectDurations;
    int potions, drinkTimes, potionDuration;
    cin >> potions >> drinkTimes;

    //Loads a priority_queue in descending order
    for(int x = 0; x < potions; x++){
        cin >> potionDuration;
        affectDurations.push(potionDuration);
    }
    //Now determining if you can drink it all before any affect expires!
    bool possible = true;
    //Only need to test the current potion-duration is long enough to allow 
    //The other potions to be drunk!
    //Remember that the longest lasting potions are at front of queue
    potions--;
    while(!affectDurations.empty() && possible){ 
        possible = (affectDurations.top() > (drinkTimes * potions));
        potions--;
        affectDurations.pop();
    }
    (possible)? cout<<"YES"<<endl: cout<<"NO"<<endl;
    return 0;
}