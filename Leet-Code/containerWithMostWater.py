from operator import le
class Solution:
    # Returns the index of the next vertical that is taller than current outer-most vertical
    def moveLeft(self, height: List[int], index):
        shortVert = height[index]
        while index < len(height)-1 and shortVert >= height[index]:
            index += 1
        return index
    # Returns the index of the next vertical that is taller than current outer-most vertical
    def moveRight(self, height: List[int], index):
        shortVert = height[index]
        while index > 0 and shortVert >= height[index]:
            index -=1
        return index

    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        #Assume the greatest area is with widest verticals, and move inwards until a larger is found
        currA = min(height[left], height[right]) * (right - left)
        while left < right: 
            if min(height[left], height[right]) == height[left]: #If left index points to smallest vertical, move that to right
                left = self.moveLeft(height, left)
                if left >= right:
                    return currA
                if currA < min(height[left], height[right]) * (right - left): #If a larger area is found, latch that
                    currA =  min(height[left], height[right]) * (right - left)
            else: #If right index points to smallest vertical, move that to left
                right = self.moveRight(height, right)
                if left >= right:
                    return currA
                if currA < min(height[left], height[right]) * (right - left): #If a larger area is found, latch that
                    currA =  min(height[left], height[right]) * (right - left)
        return currA
            

