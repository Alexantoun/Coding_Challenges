class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        dups = 0
        for i in range (0 , len(nums)-1):
            while(nums[i+1]!=None and nums[i] == nums[i+1]):
                del nums[i+1]
                nums.append(None)
                dups += 1

        return (len(nums)-dups)
                
                