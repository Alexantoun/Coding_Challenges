#Problem is the "First and Last Position of Element in Sorted Array"
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        print(nums)
        found = False 
        notFound = [-1,-1]
        length = len(nums)
        start = 0
        end = length-1
        avgIndex = int(end/2)
        #Finge cases
        if length == 0:
            return notFound
        elif length == 1:
            if nums[0] == target:
                return [0,0]
            else:
                return notFound
        elif nums[-1] < target:
            return notFound
        elif nums[0] > target:
            return notFound
        elif nums[avgIndex]<target:
            start = avgIndex
        elif nums[avgIndex]> target:
            end = avgIndex
        elif nums[avgIndex] == target:
             start = avgIndex
             while start-1 >= 0 and nums[start-1]==target:
                 start -= 1
             end = avgIndex
             while end+1 <= length-1 and nums[end + 1]==target:
                 end +=1
             return [start, end]

        while not found and start!=end:
            #print(start, ' ',end)
            avgIndex = int((start+end)/2)
            if nums[avgIndex]>=target and nums[end]!=target:
                end = avgIndex
                if nums[end-1]<target and nums[end]>target:
                    return notFound
            if nums[avgIndex]<=target and nums[start]!=target:
                start = avgIndex
                if nums[start+1]>target and nums[start]<target:
                    return notFound
                elif nums[start+1]==target:
                    start+=1

            if nums[start] == target:
                while (start-1>0 and nums[start-1] == target):
                        start-=1
            if nums[end] == target:
                while (end+1 < length-1 and nums[end+1]==target):
                    end+=1

            if nums[start] == target and nums[end] == target:
                found = True
        
        return [start,end]
                    
                

                