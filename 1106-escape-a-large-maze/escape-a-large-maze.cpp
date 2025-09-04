class Solution {
public:
    const int LIMIT = 200; // blockers are <= 200, max enclosed area is small
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    bool bfs(vector<int>& start, vector<int>& finish, unordered_set<long long>& blocked) {
        queue<pair<int,int>> q;
        unordered_set<long long> visited;

        auto encode = [&](int x, int y) {
            return ((long long)x << 20) + y;  // unique key
        };

        q.push({start[0], start[1]});
        visited.insert(encode(start[0], start[1]));

        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            if (x == finish[0] && y == finish[1]) return true; // reached target

            for (auto [dx,dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= 1e6 || ny >= 1e6) continue;

                long long key = encode(nx, ny);
                if (blocked.count(key) || visited.count(key)) continue;

                visited.insert(key);
                q.push({nx, ny});
            }

            // If visited > LIMIT*LIMIT, we escaped
            if (visited.size() > LIMIT * LIMIT) return true;
        }

        return false;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<long long> blockedSet;
        for (auto &b : blocked) {
            long long key = ((long long)b[0] << 20) + b[1];
            blockedSet.insert(key);
        }

        // Need to check both directions: source -> target and target -> source
        return bfs(source, target, blockedSet) && bfs(target, source, blockedSet);
    }
};
