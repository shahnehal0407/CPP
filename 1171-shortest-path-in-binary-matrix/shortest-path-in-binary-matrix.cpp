class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<>> pq;

        dist[0][0] = 1;
        pq.push({1, {0, 0}});

        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!pq.empty()) {
            auto [d, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;

            if (x == n - 1 && y == n - 1) return d;

            for (int dir = 0; dir < 8; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                    if (d + 1 < dist[nx][ny]) {
                        dist[nx][ny] = d + 1;
                        pq.push({d + 1, {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};
