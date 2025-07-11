class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& nodes, int& edgeCount) {
        visited[node] = true;
        nodes.push_back(node);
        for (int neighbor : adj[node]) {
            edgeCount++;  // Count both directions
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, nodes, edgeCount);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeCount = 0;

        // Step 2: Traverse all components
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> nodes;
                int edgeCount = 0;
                dfs(i, adj, visited, nodes, edgeCount);

                int k = nodes.size();
                int actualEdges = edgeCount / 2;  // Since undirected, counted twice
                int expectedEdges = k * (k - 1) / 2;

                if (actualEdges == expectedEdges) {
                    completeCount++;
                }
            }
        }

        return completeCount;
    }
};
