class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0;
        int step=0;
        int check=0;
        for(int i=0;i<nums.size()-1;i++){
            step=max(step,i+nums[i]);
            if(check==i){
                ans++;
                check=step;
            }
        }
        return ans;
    }
};