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
    bool isequal(TreeNode* a, TreeNode* b){
        if(!a && !b)return true;
        if(!a || !b || a->val!=b->val)return false;
        return isequal(a->left,b->left) && isequal(a->right, b->right); 
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(!root)return false;
        if(isequal(root,subroot))return true;

     return isSubtree(root->left,subroot) || isSubtree(root->right,subroot);

    }
};