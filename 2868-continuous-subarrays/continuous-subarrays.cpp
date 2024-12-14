typedef long long int ll;
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
     int n = nums.size();
       ll result = 0;
        
        multiset<int> all;
        int r = -1;
        for (int l = 0; l < n; l ++) {
            if (l > r) {
                all.insert(nums[l]);
                r = l;
            }
            
            while (r < n && (*all.rbegin() - *all.begin()) <= 2) {
                r ++;
                if (r < n) all.insert(nums[r]);
            }
            result += (r - l);
            
            all.erase(all.find(nums[l]));
        }
        return result;  
    } 
};