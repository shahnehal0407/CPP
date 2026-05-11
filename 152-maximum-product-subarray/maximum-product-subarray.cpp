class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int mi=nums[0];
        int mx=nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)swap(mi,mx);

            mi=min(nums[i],mi*nums[i]);
            mx=max(nums[i],mx*nums[i]);
            ans=max(mx,ans);
        }

        return ans;
    }
};