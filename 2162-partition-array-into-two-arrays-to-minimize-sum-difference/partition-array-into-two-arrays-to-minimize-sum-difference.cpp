class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        unordered_map<int, vector<int>> leftSum, rightSum;

        auto getSubsets = [&](vector<int>& arr, unordered_map<int, vector<int>>& sumMap) {
            int size = arr.size();
            for (int mask = 0; mask < (1 << size); ++mask) {
                int cnt = 0, sum = 0;
                for (int i = 0; i < size; ++i) {
                    if (mask & (1 << i)) {
                        sum += arr[i];
                        ++cnt;
                    }
                }
                sumMap[cnt].push_back(sum);
            }
        };

        getSubsets(left, leftSum);
        getSubsets(right, rightSum);

        for (auto& [k, v] : rightSum)
            sort(v.begin(), v.end());

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int res = INT_MAX;

        for (int k = 0; k <= n; ++k) {
            vector<int>& l = leftSum[k];
            vector<int>& r = rightSum[n - k];

            for (int sumLeft : l) {
                int target = totalSum / 2 - sumLeft;
                auto it = lower_bound(r.begin(), r.end(), target);

                if (it != r.end()) {
                    int sumRight = *it;
                    int curr = sumLeft + sumRight;
                    res = min(res, abs(totalSum - 2 * curr));
                }
                if (it != r.begin()) {
                    --it;
                    int sumRight = *it;
                    int curr = sumLeft + sumRight;
                    res = min(res, abs(totalSum - 2 * curr));
                }
            }
        }

        return res;
    }
};
