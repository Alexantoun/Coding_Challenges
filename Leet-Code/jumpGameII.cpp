class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size()-1;
        if(size < 1)
            return 0;
	//jumps is number of jumps taken, furthest is how far we can go from current spot till currEnd
	//currEnd is the final spot of the previous jump, when we reach that, its time to consider next jump
        int jumps = 0, furthest = 0, currEnd =0 ; 
        for(int i = 0; i < size; i ++){
            furthest = max(furthest, i+nums[i]); //Sets furthest we can jump from current position
            if (i == currEnd){ //We reached the end of the prev jump, so we consider next jump
                jumps++;
                currEnd = furthest; //the "next jump" should be the furthest spot we can get to
            }
        }
        return jumps;
    }
};
