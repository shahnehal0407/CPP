class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int count = 0;
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) count++;
        }

        for(int i = n - 1; i >= n - count; i--){
            if(nums[i] == 0) ans++;
        }

        return count - ans;
    }
};