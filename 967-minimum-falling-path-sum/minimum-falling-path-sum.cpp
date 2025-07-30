class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> last = matrix[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            vector<int> dp(n, -1);
            for (int j = 0; j < n; j++) {
                int down = last[j];
                int left = (j > 0) ? last[j - 1] : INT_MAX;
                int right = (j < n - 1) ? last[j + 1] : INT_MAX;

                dp[j] = matrix[i][j] + min(down, min(left, right));
            }
            last = dp;
        }

        return *min_element(last.begin(), last.end());
    }
};
