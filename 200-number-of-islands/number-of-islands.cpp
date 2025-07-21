class Solution {
public:
    void bfs(int r0, int c0, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({r0, c0});
        vis[r0][c0] = 1;

  
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int dr = r + row[k];
                int dc = c + col[k];
                if (dr >= 0 && dr < n && dc >= 0 && dc < m &&
                    !vis[dr][dc] && grid[dr][dc] == '1') {
                    vis[dr][dc] = 1;
                    q.push({dr, dc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
                int n = grid.size();
        int m = grid[0].size();
        int count=0;
        vector<vector<int>> vis(n, vector<int>(m, 0));


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && grid[i][j] == '1') {

                    bfs(i, j, vis, grid);
                    count++;

                }
            }
        }

        return count;
    }
};