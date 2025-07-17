class Solution {
public:

    // DFS to mark all 'O's connected to border
    void dfs(int a, int b, vector<vector<int>>& vis, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        vis[a][b] = 1;

        for(int i = 0; i < 4; i++) {
            int nrow = a + drow[i];
            int ncol = b + dcol[i];

            // ✅ CORRECTION: changed 'o' to 'O' here
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
               && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Traverse top and bottom borders
        for(int i = 0; i < m; i++) {
            // ✅ CORRECTION: changed 'o' to 'O' here
            if(!vis[0][i] && board[0][i] == 'O') dfs(0, i, vis, board);

            // ✅ CORRECTION: changed 'o' to 'O' here
            if(!vis[n-1][i] && board[n-1][i] == 'O') dfs(n-1, i, vis, board);
        }

        // Traverse left and right borders
        for(int i = 1; i < n - 1; i++) {
            // ✅ CORRECTION: changed 'o' to 'O' here
            if(!vis[i][0] && board[i][0] == 'O') dfs(i, 0, vis, board);

            // ✅ CORRECTION: changed 'o' to 'O' here
            if(!vis[i][m-1] && board[i][m-1] == 'O') dfs(i, m-1, vis, board);
        }

        // Flip all unvisited 'O's to 'X'
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // ✅ CORRECTION: changed 'o' to 'O' here
                if(!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
