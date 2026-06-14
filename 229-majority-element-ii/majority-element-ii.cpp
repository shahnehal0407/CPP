class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        if (n == 0) return ans;

        sort(nums.begin(), nums.end());

        int count = 1;
        int e = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == e) {
                count++;
            } else {
                if (count > n / 3) {
                    ans.push_back(e);
                }

                e = nums[i];
                count = 1;
            }
        }

        // Check last group
        if (count > n / 3) {
            ans.push_back(e);
        }

        return ans;
    }
};