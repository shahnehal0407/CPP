// class Solution {
// public:

// int quickSelect(vector<int>& nums, int left, int right, int k) {
//     int pivot = nums[right], pos = left;
//     for (int i = left; i < right; ++i)
//         if (nums[i] > pivot)
//             swap(nums[i], nums[pos++]);
//     swap(nums[pos], nums[right]);
    
//     int rank = pos - left + 1;
//     if (rank == k) return nums[pos];
//     else if (rank > k) return quickSelect(nums, left, pos - 1, k);
//     else return quickSelect(nums, pos + 1, right, k - rank);
// }

// int findKthLargest(vector<int>& nums, int k) {
//     return quickSelect(nums, 0, nums.size() - 1, k);
// }

// };








class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>minheap;
        for(int i=0;i<nums.size();i++){
            minheap.push(nums[i]);
            if(minheap.size()>k)minheap.pop();
        }
        return minheap.top();
    }
};