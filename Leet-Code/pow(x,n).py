class Solution:      
    def fastPowers(self, x: float, n: int):
        if(n == 0):
            return 1
        elif n%2 == 0:
            temp = self.fastPowers(x, n/2)
            return (temp*temp)
        else:
            return (x*self.fastPowers(x, n-1))
            

    def myPow(self, x: float, n: int) -> float:
        if(n < 0):
            n = -n
            x = 1/x
        return self.fastPowers(x, n)
        
        
        
        