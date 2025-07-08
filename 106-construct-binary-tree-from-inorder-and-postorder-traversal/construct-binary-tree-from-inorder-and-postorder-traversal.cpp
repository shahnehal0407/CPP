/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& postorder, int start, int end, unordered_map<int,int>& store, int& postIndex) {
        if (start > end) return nullptr;

        int rootval = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootval);
        int mid = store[rootval];

        // \U0001f501 Recurse RIGHT first, then LEFT
        root->right = helper(postorder, mid + 1, end, store, postIndex);
        root->left = helper(postorder, start, mid - 1, store, postIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> store;
        int postIndex = postorder.size() - 1;

        for (int i = 0; i < inorder.size(); i++) {
            store[inorder[i]] = i;
        }

        return helper(postorder, 0, inorder.size() - 1, store, postIndex);
    }
};
