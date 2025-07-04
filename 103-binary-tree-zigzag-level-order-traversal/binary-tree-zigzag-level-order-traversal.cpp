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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
               vector<vector<int>>ans;
        queue<TreeNode*>store;
        if(root==NULL)return ans;
        store.push(root);
        while(!store.empty()){
        int n=store.size();
        vector<int>level;
        for(int i=0;i<n;i++){
            TreeNode * node = store.front();
            if(node->left!=NULL)store.push(node->left);
            if(node->right!=NULL)store.push(node->right);
            store.pop();
            level.push_back(node->val);
            
        }
        ans.push_back(level);
        }

        for (int i = 0; i < ans.size(); ++i) {
        if (i % 2 == 1) {
            reverse(ans[i].begin(), ans[i].end());
        }
    }
        return ans ;

    }
};