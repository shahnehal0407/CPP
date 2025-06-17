class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int j = 0;
        int count = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];

            while (count > goal) {
                count -= nums[j];
                j++;
            }

            ans += i - j + 1; 
        }

        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
         return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};