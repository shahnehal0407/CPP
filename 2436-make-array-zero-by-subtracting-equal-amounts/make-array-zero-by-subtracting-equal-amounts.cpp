class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        if (s.size()!=0 && *s.begin()==0) return s.size()-1;
        else return s.size();
        
    }
};