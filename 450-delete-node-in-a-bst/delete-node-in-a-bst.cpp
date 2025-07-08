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
    TreeNode* insertAtLeftmost(TreeNode* root, TreeNode* nodeToInsert) {
        if (!root) return nodeToInsert;
        TreeNode* curr = root;
        while (curr->left != nullptr) {
            curr = curr->left;
        }
        curr->left = nodeToInsert;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Found the node to delete
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            delete root;

            // Now attach left subtree to the leftmost of right subtree
            return insertAtLeftmost(right, left);
        }
        return root;
    }
};
