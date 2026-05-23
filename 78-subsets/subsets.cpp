class Solution {
public:

    void backtrack(int in,vector<int>& nums,vector<vector<int>> & ans, vector<int> &temp){
        ans.push_back(temp);
        for(int i=in;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(i+1,nums,ans,temp);
            temp.pop_back();
        }

    }




    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        backtrack(0,nums,ans,temp);

        return ans;
    }
};