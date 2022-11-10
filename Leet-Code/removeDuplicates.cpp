class Solution {
public:
    string removeDuplicates(string s) {
        if(s.length() < 1)
            return "";
        string solution = "";
        solution+=s[0];
        for(int i =1; i < s.length(); i++){
            if(solution.back() == s[i]){
                solution.pop_back();
            }
            else
                solution+=s[i];
            // cout<<solution<<endl;
        }
        return solution;
    }
};
