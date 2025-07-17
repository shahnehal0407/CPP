class Solution {
public:

    // DFS to mark all 'O's connected to border
    void dfs(int a, int b, vector<vector<int>>& vis, vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        vis[a][b] = 1;

        for(int i = 0; i < 4; i++) {
            int nrow = a + drow[i];
            int ncol = b + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
               && !vis[nrow][ncol] && board[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, board);
            }
        }
    }
int numEnclaves(vector<vector<int>>& board)  {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Traverse top and bottom borders
        for(int i = 0; i < m; i++) {

            if(!vis[0][i] && board[0][i] == 1) dfs(0, i, vis, board);

            if(!vis[n-1][i] && board[n-1][i] == 1) dfs(n-1, i, vis, board);
        }

        // Traverse left and right borders
        for(int i = 1; i < n - 1; i++) {

            if(!vis[i][0] && board[i][0] == 1) dfs(i, 0, vis, board);

            if(!vis[i][m-1] && board[i][m-1] ==1) dfs(i, m-1, vis, board);
        }
            int count =0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
          
                if(!vis[i][j] && board[i][j] == 1)
                   count++;
            }
        }
        return count;
    }
};
