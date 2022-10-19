class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        #Fringe cases
        if nums[-1]<target:
            return len(nums)
        elif nums[0]>target:
            return 0
        else:
            print(nums)
            start = 0
            end = len(nums)-1
            middleIndex = int((start+end)/2)