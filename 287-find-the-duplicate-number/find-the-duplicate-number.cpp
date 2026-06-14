class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>vis(nums.size()-1,0);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(vis[nums[i]-1]==1){ans= nums[i];break;}
            else vis[nums[i]-1]=1;
        }

        return ans;
    }
};