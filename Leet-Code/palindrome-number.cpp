//Palindrome-number challenge without converting the number into a string or cstring
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        bool isPalindrome = true;

        if(x>0)
        {
            int maxPower=0
            int notX = x, stopper;
            maxPower = static_cast<int>(log10(x));
            stopper = int((maxPower+1)/2);
            cout<<stopper<<endl;
            for(int i = maxPower; i>=stopper; i--)
            {
                if(x/(int(pow(10,maxPower)))%10 != notX%10)
                {
                    isPalindrome = false;
                    break; 
                }
                notX/=10;
                maxPower--;
            }
        }
        else if(x < 0)
            isPalindrome = false;
    
        return isPalindrome;
    }
};