class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> sorted;
        for(int i = n - 1; i >= 0; i--) {
            int pos = lower_bound(sorted.begin(),sorted.end(),nums[i])-sorted.begin();
            ans.push_back(pos);
            sorted.insert(sorted.begin() + pos, nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};