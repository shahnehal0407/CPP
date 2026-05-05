class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        set<vector<int>>ans;
        vector<int>temp;
        backtrack(nums,freq,ans,temp);
        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }


    void backtrack(vector<int>& nums, unordered_map<int,int> &freq, set<vector<int>> & ans, vector<int> &temp){
        if(temp.size()==nums.size()){ans.insert(temp); return ;}
        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]]==0)continue;

            freq[nums[i]]--;
            temp.push_back(nums[i]);
            backtrack(nums,freq,ans,temp);

            freq[nums[i]]++;
            temp.pop_back();
        }
    }
};