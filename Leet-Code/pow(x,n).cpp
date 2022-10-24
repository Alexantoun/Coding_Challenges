class Solution {
public:
    double fast_power(const double& x, uint n){
        double temp;
        if(n == 0)
            return 1;
        else if (n%2 == 0){
            temp = fast_power(x, n/2);
            return temp*temp;
        }
        else 
            return (x*fast_power(x, n-1));
    }
    
    double myPow(double x, int n) {
        uint n2;
        if(n < 0){
            n2 = -1 * uint(n);
            x = 1/x;
        }
        else
            n2 = n;
        return fast_power(x, n2);
    }
};