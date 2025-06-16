

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ans;
//         for(int i=0;i<=nums.size()-k;i++){
//             int m=0;
//             int res=nums[i];
//             while(m<k){
//                 m++;
//                 res =max(res,nums[i+m]);

//             }
//             ans[i]=res;
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> result;
        for(int i = 0; i < n; i++){
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if(dq.front() <= i-k) dq.pop_front();
            if(i >= k-1) result.push_back(nums[dq.front()]);
        }
        return result;
    }
};