class Solution {
public:
  
         vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {  
        unordered_map<int, int> mp;
        stack<int> temp;

        for(int i = nums2.size() - 1; i >= 0; --i){
            while(!temp.empty() && temp.top() <= nums2[i]){
                temp.pop();
            }

            if(temp.empty()) mp[nums2[i]] = -1;
            else mp[nums2[i]] = temp.top();

            temp.push(nums2[i]);
        }

        vector<int> ans;
        for(int num : nums1){
            ans.push_back(mp[num]);
        }

        return ans;

    }
};