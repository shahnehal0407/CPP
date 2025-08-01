class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % k != 0) return false;

        int target = totalSum / k;
        vector<bool> visited(n, false);
        sort(nums.begin(), nums.end(), greater<int>()); // optimization

        return backtrack(nums, visited, 0, 0, k, target);
    }

private:
    bool backtrack(vector<int>& nums, vector<bool>& visited, int start, int currSum, int k, int target) {
        if (k == 1) return true;  // only one bucket left → must be valid
        if (currSum == target) {
            // current bucket is full, try next bucket
            return backtrack(nums, visited, 0, 0, k - 1, target);
        }

        for (int i = start; i < nums.size(); i++) {
            if (visited[i] || currSum + nums[i] > target) continue;

            visited[i] = true;
            if (backtrack(nums, visited, i + 1, currSum + nums[i], k, target)) return true;
            visited[i] = false;

            // optimization: if first element in subset fails, no point trying others of same value
            if (currSum == 0) return false;
        }

        return false;
    }
};
