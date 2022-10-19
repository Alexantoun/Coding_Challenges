class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        values ={}
        results = []
        for x in range(len(nums)): #store value and index as list
            if nums[x] in values:
                values[nums[x]].append(x)
            else:
              values.update({nums[x]:[x]})  
        
        # keys = values.keys()
        # vals = values.values()
        # print(f"{keys}\n{vals}")
        for x in range(len(nums)):
            curr = nums[x]
            targ = target - curr
            if targ in values:
                results = [x] + values[targ]
                return results



