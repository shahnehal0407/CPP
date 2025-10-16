class Solution {
public:
    unordered_map<int, int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py)
            parent[px] = py;
    }

    int removeStones(vector<vector<int>>& stones) {
        // Initialize parent for all possible nodes
        for (auto& s : stones) {
            int x = s[0];
            int y = s[1] + 10001;  // offset y to avoid collision with x
            if (!parent.count(x)) parent[x] = x;
            if (!parent.count(y)) parent[y] = y;
            unionSet(x, y);
        }

        // Find unique components
        unordered_set<int> components;
        for (auto& s : stones) {
            components.insert(find(s[0]));
        }

        // Total stones - connected components
        return stones.size() - components.size();
    }
};
