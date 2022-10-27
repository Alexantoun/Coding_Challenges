//  Boyer-Moore Voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,int> amounts; //key = number from nums, value = number of times it appeared
        unordered_map<int,int>::iterator itr;
        vector<int> solution_set; //Holds elements that occur more than n/3 times
        
        for(int i =0; i < size; i++){
            itr = amounts.find(nums[i]);
            if(amounts.find(nums[i]) != amounts.end()){
                if(itr->second > size/3) //No need to re-add a value already added to solution_set
                    continue;
                itr->second++;
            }
            else{
                amounts.insert({nums[i], 1});
                itr = amounts.find(nums[i]); 
            }//Edge case is when n<3, , all elements will appear at least 1/3*n times
            if(itr->second > size/3)
                solution_set.push_back(itr->first);
        }
        return solution_set;
    }
};