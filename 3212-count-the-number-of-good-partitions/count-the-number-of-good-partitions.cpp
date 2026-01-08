class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> last;

        // Step 1: record last occurrence
        for (int i = 0; i < nums.size(); i++) {
            last[nums[i]] = i;
        }

        long long ans = 1;
        int right = 0;

        // Step 2: sweep
        for (int i = 0; i < nums.size() - 1; i++) {
            right = max(right, last[nums[i]]);
            if (i == right) {
                ans = (ans * 2) % MOD;
            }
        }

        return ans;
    }
};
