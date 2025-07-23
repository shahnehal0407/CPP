class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for (auto& flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        // Queue stores: {stops, node, cost}
        queue<tuple<int, int, int>> q;
        q.push({0, src, 0});

        // minCost[node][stops] = minimum cost to reach `node` using `stops`
        vector<vector<int>> minCost(n, vector<int>(k + 2, INT_MAX));
        minCost[src][0] = 0;

        while (!q.empty()) {
            auto [stops, node, cost] = q.front();
            q.pop();

            if (stops > k) continue;

            for (auto& [next, price] : adj[node]) {
                int newCost = cost + price;
                if (newCost < minCost[next][stops + 1]) {
                    minCost[next][stops + 1] = newCost;
                    q.push({stops + 1, next, newCost});
                }
            }
        }

        // Find the minimum cost to reach dst with at most k+1 flights
        int ans = INT_MAX;
        for (int i = 0; i <= k + 1; ++i) {
            ans = min(ans, minCost[dst][i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
