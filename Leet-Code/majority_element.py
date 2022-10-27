class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        size = len(nums)
        amounts = {}
        solution = []
        for i in range (size):
            if nums[i] in amounts:
                if amounts[nums[i]] > int(size/3):
                    continue
                amounts[nums[i]]+=1
            else:
                amounts[nums[i]] = 1
            if amounts[nums[i]] > int(size/3):
                solution.insert(nums[i])
        
        return solution


# Boyer-Moore Voting Algorithm