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
    void inorder(TreeNode* root, vector<TreeNode*>& store) {
        if (!root) return;
        inorder(root->left, store);
        store.push_back(root);
        inorder(root->right, store);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*>store;
        inorder(root,store);
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
       for(int i=0;i<store.size()-1;i++){
        if(store[i]->val>store[i+1]->val){
    if(! first) {first=store[i]; second=store[i+1];}
            else second=store[i+1];
        }
       }
              
       if (first && second) {
            swap(first->val, second->val);
        }

    }
};