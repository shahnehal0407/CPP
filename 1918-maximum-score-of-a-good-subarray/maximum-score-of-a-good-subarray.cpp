class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int left =k;
        int right =k;
        int minvalue = nums[k];
        int maxscore = nums[k];
        while(left>0 || right<n-1){
            if(left==0)right++;
            else if(right==n-1)left--;
            else if(nums[left-1]>nums[right+1])left--;
            else right++;
            minvalue = min(minvalue, min(nums[left],nums[right]));
            maxscore = max(maxscore, minvalue*(right-left+1));
        }
        return maxscore;
    }
};