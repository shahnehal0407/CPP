class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = (n + 1) / 2; // safe even for odd-sized arrays
        int count = 0;

        while (i < n / 2 && j < n) {
            if (2 * nums[i] <= nums[j]) {
                count++;
                i++;
            }
            j++;
        }

        return 2 * count;
    }
};
