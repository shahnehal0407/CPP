class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // If sum is odd, we cannot partition it into two equal subsets
        if (sum % 2 != 0) return false;

        int target = sum / 2;

        // dp[i][t] = can we form sum t using elements from 0 to i
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base case: sum = 0 is always possible
        for (int i = 0; i < n; i++) dp[i][0] = true;

        // Base case: if first number is within target, mark it true
        if (nums[0] <= target) dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= target; t++) {
                bool notTake = dp[i - 1][t];
                bool take = false;
                if (nums[i] <= t)
                    take = dp[i - 1][t - nums[i]];
                dp[i][t] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
};
