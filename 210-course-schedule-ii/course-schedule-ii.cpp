class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& recStack, stack<int>& st) {
        vis[node] = 1;
        recStack[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, recStack, st)) return true;
            } else if (recStack[it]) {
                return true;
            }
        }

        recStack[node] = 0;
        st.push(node);
        return false;
    }

    vector<int> findOrder(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v);
        for (auto edge : edges) {
            int u = edge[0];
            int v_ = edge[1];
            adj[u].push_back(v_);
        }

        vector<int> vis(v, 0), recStack(v, 0);
        stack<int> st;

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, recStack, st)) {
                    return {}; 
                }
            }
        }

        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }

        reverse(topo.begin(), topo.end()); 
        return topo;
    }
};
