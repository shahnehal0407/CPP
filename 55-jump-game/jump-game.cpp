class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step=0;

        for(int i=0;i<nums.size();i++){
            if(i>step)return false;
            if(step>=nums.size())return true;
            step=max(i+nums[i],step);
        }
        return true;
    }
};