class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest1 = INT_MAX;
        int closest2 = INT_MIN;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum >= target) {
                    closest1 = min(closest1, sum);
                    k--;
                } else {
                    closest2 = max(closest2, sum);
                    j++;
                }
            }
        }

        // Edge case handling
        if (closest1 == INT_MAX) return closest2; // all sums < target
        if (closest2 == INT_MIN) return closest1; // all sums >= target

        // Return whichever is closer to target
        if (abs(target - closest2) > abs(closest1 - target))
            return closest1;
        else
            return closest2;
    }
};
