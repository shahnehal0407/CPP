class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int final =INT_MIN;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans+nums[i];

            if(ans>final){
                final =ans;
            }
            if(ans<0)ans=0;
        }
        return final;
    }

};