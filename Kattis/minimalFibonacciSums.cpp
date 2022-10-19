#include <iostream>
#include <stack>
#include <list>
using namespace std;

//Fills stack with every int that is less than target_value. 
void fibonacciSequence(stack<int>& fib_seq, const int& target_value){
    int second_last = 1, temp; 
    //
    fib_seq.push(0);
    fib_seq.push(1);
    fib_seq.push(1);
    
    while(fib_seq.top()<target_value){
        temp = fib_seq.top();
        fib_seq.push(fib_seq.top()+second_last);
        second_last = temp;
    }
    // fib_seq.pop(); //You can't assume the input is not in fib sequence itself
                    //Therefore you cant just drop the last element
}

int main(){
    stack<int> fib_sequence;
    list<int> operands;
    int target_sum;

    cin>>target_sum;
    //Fill stack with fib sequence upto target_sum
    fibonacciSequence(fib_sequence, target_sum);

    //Add all values in stack that can sum upto target_value
    while(target_sum>0){
        while(fib_sequence.top()>target_sum)//If whats in stack is too big, drop them
            fib_sequence.pop();

        operands.push_back(fib_sequence.top());
        target_sum -= fib_sequence.top();
        fib_sequence.pop();
    }
    //Print the list of operands in ascending order
    list<int>::iterator itr = operands.end();
    do{
        itr--;
        cout<<*itr<<' ';
    }while(itr != operands.begin());
    cout<<endl;
   
    return 0;
}