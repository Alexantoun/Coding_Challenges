class Solution:
    def reverse(self, x: int) -> int:
        if x <= (-2**31) or x >= (2**31)-1: #Return 0 if not 32-bit integer
            return 0
        elif x < 0: #Make positive if negative & Flag
            isNeg = True
            x = x*(-1)
        else:
            isNeg = False
            
        newX = int(0) 
        while x > 0: #Move last element of X into the next (starting at 0) index of newX
            newX = newX*10
            newX = newX + (x%10)
            x = int(x/10)
            # print(f"newX = {newX} and X = {x}")
            
        if isNeg: #Make negative again if flagged
            newX = newX*-1
            
        if newX <= (-2**31) or newX >= (2**31)-1: #Check if newX is 32-bit integer
            return 0
        else:
            return newX