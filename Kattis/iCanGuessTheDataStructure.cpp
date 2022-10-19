#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> pq;
    queue<int> q;
    stack<int> stk;
    int numInputs, command, value;
    bool canStk = true, canPQ = true, canQ = true;

    while(cin>>numInputs){
        for(int x =0; x < numInputs; x++){
            cin>>command>>value;
            if(command == 1){
                q.push(value);
                stk.push(value);
                pq.push(value);
            } else{ //Determines which data structure it can be
                if(q.empty() || (canQ && q.front() != value)) //Cant be q if its empty or if front!= value
                    canQ = false;
                if(stk.empty() || (canStk && stk.top() != value))//Cant be stack if its empty or if top != value
                    canStk = false;
                if(pq.empty() || (canPQ && pq.top() != value) )//Cant be priority queue if its empty or if top != value
                    canPQ = false;
                //Below block is to prevent seg-faults
                if(!q.empty())
                    q.pop();
                if(!stk.empty())
                    stk.pop();
                if(!pq.empty())
                    pq.pop();
            }  
        }
        if(canPQ && !canStk && !canQ)
            cout<<"priority queue"<<endl;
        else if(canStk && !canPQ && !canQ)
            cout<<"stack"<<endl;
        else if(canQ && !canPQ && !canStk)
            cout<<"queue"<<endl;
        else if(!canQ && !canPQ && !canStk)
            cout<<"impossible"<<endl;
        else
            cout<<"not sure"<<endl;
        //Clear data structures and reset bools 
        pq = priority_queue<int>();     
        q = queue<int>();
        stk = stack<int>();
        canStk = true;
        canPQ = true;
        canQ = true;
    }
    return 0;
}