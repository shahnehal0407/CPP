class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n, 0);

        for (int j = 0; j < n; j++) {
            int mx = 0;
            for (int i = 0; i < m; i++) {
                int len = (int)to_string(grid[i][j]).size();
                mx = max(mx, len);
            }
            ans[j] = mx;
        }
        return ans;
    }
};
