class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int n = nums.size();
        int left = -1, right = -1;

        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i+1]) {
                left = i;
                break;
            }
        }

        if(left == -1) return 0;

        for(int i = n - 1; i > 0; i--) {
            if(nums[i] < nums[i-1]) {
                right = i;
                break;
            }
        }

        int sub_min = INT_MAX;
        int sub_max = INT_MIN;

        for(int i = left; i <= right; i++) {
            sub_min = min(sub_min, nums[i]);
            sub_max = max(sub_max, nums[i]);
        }

        while(left > 0 && nums[left-1] > sub_min) left--;
        while(right < n-1 && nums[right+1] < sub_max) right++;

        return right - left + 1;
    }
};