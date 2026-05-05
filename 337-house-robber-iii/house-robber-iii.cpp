class Solution {
public:
    pair<int, int> solve(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        // If we rob current node, we cannot rob left and right child
        int robCurrent = root->val + left.second + right.second;

        // If we do not rob current node, we can take max from children
        int notRobCurrent = max(left.first, left.second) + 
                            max(right.first, right.second);

        return {robCurrent, notRobCurrent};
    }

    int rob(TreeNode* root) {
        pair<int, int> ans = solve(root);

        return max(ans.first, ans.second);
    }
};