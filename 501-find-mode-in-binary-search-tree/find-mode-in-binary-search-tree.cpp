class Solution {
public:
    unordered_map<int, int> mp;

    void dfs(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        mp[root->val]++;

        dfs(root->left);
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ans;

        dfs(root);

        int maxFreq = 0;

        for (pair<int, int> p : mp) {
            maxFreq = max(maxFreq, p.second);
        }

        for (pair<int, int> p : mp) {
            if (p.second == maxFreq) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};