class Solution {
public:

 int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int j = 0;
        int count = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
             if(nums[i]%2!=0) count++;

            while (count > goal) {
                if(nums[j]%2!=0) count--;
                j++;
            }

            ans += i - j + 1; 
        }

        return ans;
    }




    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);

    }
};