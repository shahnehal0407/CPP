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

    int build(TreeNode* root, long long targetSum){
        int res=0;
        if(root==nullptr)return 0;
        if((long long)root->val==targetSum)res++;
        res+=build(root->left,targetSum-root->val);
        res+=build(root->right,targetSum-root->val);
        return res;

    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)return 0;
        return pathSum(root->left,targetSum)+build(root,(long long)targetSum)+pathSum(root->right,targetSum);
    }
};