class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int zeros=0;
        int ans=0;
        for(i;i<nums.size();i++){
            if(nums[i]==0) zeros++;

            while(zeros>k){
                if(nums[j]==0)zeros--; 
                j++;
                
            }
            ans=max(ans, i-j+1);
        }
        

        return ans;
    }
};