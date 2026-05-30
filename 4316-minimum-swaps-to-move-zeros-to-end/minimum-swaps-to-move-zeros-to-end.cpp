class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();

        int zeroCount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroCount++;
            }
        }

        int zerosAlreadyAtEnd = 0;
        for (int i = n - 1; i >= n - zeroCount; i--) {
            if (nums[i] == 0) {
                zerosAlreadyAtEnd++;
            }
        }

        return zeroCount - zerosAlreadyAtEnd;
    }
};