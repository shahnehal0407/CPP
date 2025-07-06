/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool getPath(TreeNode *root, vector<TreeNode*> &arr, TreeNode* x) {
        if (!root) return false;

        arr.push_back(root);

        if (root == x) return true;

        if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
            return true;

        arr.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arr1, arr2;
        
        // Find path from root to p and q
        getPath(root, arr1, p);
        getPath(root, arr2, q);

        TreeNode* lca = nullptr;

        // Compare the paths from start to find the last common node
        int i = 0;
        while (i < arr1.size() && i < arr2.size()) {
            if (arr1[i] == arr2[i]) {
                lca = arr1[i];
            } else {
                break;
            }
            ++i;
        }

        return lca;
    }
};
