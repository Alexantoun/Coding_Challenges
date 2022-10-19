#include <iostream>
#include <cstring>
using namespace std;

enum policy {up, down, pref};

int main(){
    char input[1001];
    //This array sotes the number of adjustments made for the corresponding policy
    int counts [3] = {0};
    cin >> input;		

    if(input[0] == 'U'){ //If the seat is initially up...
        if(input[1]=='D'){ //And first person prefers it down...
            counts[up] +=2; //Add 2 adjustments for up policy
            counts[down] +=1;//1 adjustment for down policy
            counts[pref]++;//and the adjustment for the preferred policy of toilet user
        }
    }   
    if(input[0] == 'D'){ //If the seat is initially down...
        if(input[1]=='U'){//And the first person prefers it up...
            counts[up] +=1;//1 adjustment for up policy
            counts[down] +=2;//Add 2 adjustments for down policy
            counts[pref]++;//and the adjustment for the preferred policy of toilet user
        }
    }
    if(input[0]=='U' && input[1]=='U') //If the seat is up && user wants it up -> but the policy is for down
        counts[down]++;
    if(input[0]=='D' && input[1]=='D') //If the seat is down && user wants it down -> but the policy is for up
        counts[up]++;
        
    for(int x = 2; x<strlen(input); x++){//First user already accounted for. You can assume the seat is in correct position for the current policy
                                        //Thus, the only adjustments required are for the users preference
        (input[x] =='U')? counts[down]+=2 : counts[up]+=2;
        if(input[x] != input[x-1])//The policy for user preference sees adjustments only when the previous user doesnt have same preference as current user
            counts[pref]++;
    }   
    cout<<counts[up]<<endl<<counts[down]<<endl<<counts[pref]<<endl;
}