class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxval=0;
        for(int i=0;i<nums.size();i++){
            maxval=max(maxval,nums[i]);


        }
        vector<int>store(maxval+1,0);
        for(int i=0;i<nums.size();i++){
            store[nums[i]]+=nums[i];
        }

    int prev1=0;
    int prev2=0;

    for(int i=0;i<=maxval;i++){
        int take =prev1+store[i];
        int nottake=prev2;
        int cur=max(take,nottake);
        prev1=prev2;
        prev2=cur;
    

        
    }
        return prev2;
    }
};