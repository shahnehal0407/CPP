class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> temp;
        int n = nums.size();
        vector<int> ans(n, -1);
        
        // Push the entire array once to simulate circularity
        for (int i = n - 1; i >= 0; --i) {
            temp.push(nums[i]);
        }

        // Main pass
        for (int i = n - 1; i >= 0; --i) {
            while (!temp.empty() && temp.top() <= nums[i]) {
                temp.pop();
            }
            if (!temp.empty()) ans[i] = temp.top();
            temp.push(nums[i]);
        }

        return ans;
    }
};