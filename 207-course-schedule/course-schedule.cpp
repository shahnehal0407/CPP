class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& recStack) {
        vis[node] = 1;
        recStack[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, recStack)) return true;
            } else if (recStack[it]) {
                return true;
            }
        }

        recStack[node] = 0;
        return false;
    }

    bool canFinish(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v);
        for (auto edge : edges) {
            int u = edge[0];
            int v_ = edge[1];
            adj[u].push_back(v_);
        }

        vector<int> vis(v, 0);
        vector<int> recStack(v, 0);

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, recStack)) {
                    return false; // cycle detected
                }
            }
        }

        return true; // no cycle, topological order exists
    }
};
