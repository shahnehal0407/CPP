class Solution {
public:

    void backtrack(int in,vector<int>& nums,set<vector<int>> & ans, vector<int> &temp){
        ans.insert(temp);
        for(int i=in;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(i+1,nums,ans,temp);
            temp.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            set<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());


        backtrack(0,nums,ans,temp);
        vector<vector<int>>res(ans.begin(),ans.end());

        return res;
    }
};