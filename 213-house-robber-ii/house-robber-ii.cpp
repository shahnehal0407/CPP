class Solution {
public:

    int roblinear(vector<int>& nums,int i,int j){
        int n= nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int prev1=0;
        int prev2=nums[i];

        for(int a=i+1;a<=j;a++){
            int cur=max(prev1+nums[a],prev2);
            prev1=prev2;
            prev2=cur;
        }
        return prev2;

    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        return max(roblinear(nums,0,n-2),roblinear(nums,1,n-1));

    }
};