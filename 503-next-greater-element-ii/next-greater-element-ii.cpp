class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> temp;
        vector<int>ans(nums.size(),-1);
    for(int i=nums.size()-1;i>=0;i--){
        temp.push(nums[i]);
    }

    
    for(int i=nums.size()-1;i>=0;i--){
        while(!temp.empty() && nums[i]>=temp.top()){temp.pop();}
        if(!temp.empty())ans[i]=temp.top();
        temp.push(nums[i]);
        
    }
        return ans;
    }
};