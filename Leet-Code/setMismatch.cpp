class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, bool> set;
        vector<int> solution(2);
        int max_value = 0;
        bool found_missing;
                
        for(int i = 0; i <nums.size(); i++){
            (nums[i] > max_value)? max_value = nums[i] : true;
            if(set.find(nums[i]) == set.end())
                set[nums[i]] = true;
            else
                solution[0] = nums[i];
        }    
        if(!found_missing){
            for(int i = 1; i < max_value+2; i++)
                if(set.find(i) == set.end()){
                    solution[1] = i;
                    break;
                }
        }
        return solution;
    }
};