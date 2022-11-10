class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size()-1;
        if(size < 1)
            return 0;
        int jumps = 0, furthest = 0, currEnd =0 ; 
        for(int i = 0; i < size; i ++){
            furthest = max(furthest, i+nums[i]); //Sets furthest we can jump from current position
            if (i == currEnd){
                jumps++;
                currEnd = furthest;
            }
        }
        return jumps;
    }
};
