class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n); // FIXED: changed from vector<pair<int,int>> to vector<vector<pair<int,int>>>
        for(auto road : roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> way(n, 0);
        vector<long long> dist(n, LLONG_MAX); // FIXED: changed to long long and LLONG_MAX to avoid overflow
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // FIXED: long long for time

        pq.push({0, 0});
        dist[0] = 0;
        way[0] = 1;
        int mod = 1e9 + 7;

        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();
            if (time > dist[node]) continue;
            for(auto it : adj[node]){
                if(dist[it.first] > it.second + dist[node]){
                    dist[it.first] = it.second + dist[node]; // FIXED: typo (was dis instead of dist)
                    pq.push({dist[it.first], it.first});
                    way[it.first] = way[node];
                }
                else if(dist[it.first] == it.second + dist[node]){
                    way[it.first] = (way[it.first] + way[node]) % mod; // FIXED: added modulo
                }
            }
        }

        return way[n - 1];
    }
};
