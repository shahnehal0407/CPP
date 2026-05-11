class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>store(nums.size(),1);
        int prefix=1;
        for(int i=0;i<nums.size();i++){
            store[i]=prefix;
            prefix*=nums[i];
        }
        int sufix=1;
        for(int i=nums.size()-1;i>=0;i--){
            store[i]*=sufix;
            sufix*=nums[i];
        }
        return store;
    }
};