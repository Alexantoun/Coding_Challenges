class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        perm = [] #Create empty list
        def permutation(nums, ans): #This actually gets skipped until its called below, then you backtrack to here
            if len(nums) == 0:
                perm.append(ans)
            for x in range(0,len(nums)):
                #perm is everything before current char, and everything after, 
                #ans is ans list plus the current char, but we need it in a list form, so we create a list holding that element and concat it
                #Whatever, just do one deskcheck/walkthrough with list [1,2,3] and it will make sense
                permutation(nums[:x]+nums[x+1: ], ans+[nums[x]])
        permutation(nums, [])
        return perm
