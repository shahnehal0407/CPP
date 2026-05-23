class Solution {
public:

    void backtrack(vector<vector<int>> &ans,vector<int>& freq,vector<int> &temp, vector<int>& nums){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                temp.push_back(nums[i]);
                freq[i]=1;
                backtrack(ans,freq,temp,nums);
                freq[i]=0;
                temp.pop_back();
                }
        }
    }



    vector<vector<int>> permute(vector<int>& nums) {
            vector<int>freq(nums.size(),0);
            vector<int>temp;

            vector<vector<int>>ans;
            backtrack(ans,freq,temp,nums);
            return ans;
    }
};