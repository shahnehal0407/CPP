class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build adjacency list
        vector<pair<int, int>> adj[n + 1];
        for (auto& flight : times) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // Step 2: Min heap (priority queue): stores {current_time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});

        // Step 3: Distance array initialized to infinity
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Step 4: Dijkstra's algorithm
        while (!q.empty()) {
            auto [time, node] = q.top();
            q.pop();

            for (auto [next, weight] : adj[node]) {
                if (dist[next] > time + weight) {
                    dist[next] = time + weight;
                    q.push({dist[next], next});
                }
            }
        }

        // Step 5: Compute maximum time taken
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;  // unreachable node
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
