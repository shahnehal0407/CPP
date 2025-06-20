class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int num : nums) total += num;

        int rem = total % p;
        if (rem == 0) return 0;

        int n = nums.size();
        unordered_map<int, int> lastSeen;
        lastSeen[0] = -1;

        long long prefix = 0;
        int ans = n;

        for (int i = 0; i < n; ++i) {
            prefix = (prefix + nums[i]) % p;

            int want = (prefix - rem + p) % p;

            if (lastSeen.find(want) != lastSeen.end()) {
                ans = min(ans, i - lastSeen[want]);
            }

            lastSeen[prefix] = i;
        }

        return ans == n ? -1 : ans;
    }
};
