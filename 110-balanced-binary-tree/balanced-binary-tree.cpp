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
    bool isBalanced(TreeNode* root) {
      return maxDepth(root)!=-1;
    }
    int maxDepth(TreeNode* root) {
      if(root==NULL)
            return 0;
        int l=maxDepth(root->left);
        if(l==-1)return -1;
        int r=maxDepth(root->right);
        if(r==-1)return -1;
        if(abs(r-l)>1)return -1;
       return max(l,r)+1;
    }
};