class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans=-1;
        long long store=nums[0];
        for(int i=1;i<nums.size();i++){
            if(store>nums[i] && i>=2){
                ans=store+nums[i];
            }
            store+=nums[i];
        }
        return ans;
    }
};