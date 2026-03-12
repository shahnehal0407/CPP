class Solution {
public:

    int nextIndex(vector<int>& nums, int i, int n) {
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {

            if (nums[i] == 0) continue;

            int slow = i;
            int fast = nextIndex(nums, i, n);

            while (nums[slow] * nums[fast] > 0 &&
                   nums[fast] * nums[nextIndex(nums, fast, n)] > 0) {

                if (slow == fast) {

                    if (slow == nextIndex(nums, slow, n))
                        break;

                    return true;
                }

                slow = nextIndex(nums, slow, n);
                fast = nextIndex(nums, nextIndex(nums, fast, n), n);
            }

            int val = nums[i];
            int j = i;

            while (nums[j] * val > 0) {

                int temp = nextIndex(nums, j, n);
                nums[j] = 0;
                j = temp;
            }
        }

        return false;
    }
};