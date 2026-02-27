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



    void dfs(vector<vector<int>> & ans, vector<int> & path,TreeNode* root, int targetSum ){
        if(!root)return ;
        path.push_back(root->val);
        targetSum-=root->val;
        if(!root->left && !root->right){if(targetSum==0)ans.push_back(path);}
        else {dfs(ans,path,root->left,targetSum);
        dfs(ans,path,root->right,targetSum);
        } 
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>path;
         dfs(ans,path,root,targetSum);
         return ans;
        
    }
};