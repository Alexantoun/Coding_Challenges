class Solution {
public:
    struct solution{
        int position;//current index
        int range;//How far can you jump
        int num_jump;
    };
    int jump(vector<int>& nums) {
        int target_index = nums.size()-1;
        if(target_index == 0)
            return 0;
        queue<solution> BFS; 
        solution curr;
        BFS.push(solution{0,nums[0], 0});
        while(!BFS.empty()){
            curr = BFS.front();
            BFS.pop();
            for(int i = nums[curr.position]; i > 0 ; i--){
                if(curr.position + i >= target_index)
                    return curr.num_jump + 1;
                else
                    BFS.push(solution{curr.position+1, nums[curr.position+i], curr.num_jump+1});
            }
        }
        return -9999;
    }
};
