class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return 0;

        vector<int> inc(n, 1); // increasing
        vector<int> dec(n, 1); // decreasing

        // Build inc array
        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i-1]) {
                inc[i] = inc[i-1] + 1;
            }
        }

        // Build dec array
        for(int i = n-2; i >= 0; i--) {
            if(arr[i] > arr[i+1]) {
                dec[i] = dec[i+1] + 1;
            }
        }

        int maxLen = 0;

        // Find max mountain
        for(int i = 0; i < n; i++) {
            if(inc[i] > 1 && dec[i] > 1) {
                maxLen = max(maxLen, inc[i] + dec[i] - 1);
            }
        }

        return maxLen;
    }
};