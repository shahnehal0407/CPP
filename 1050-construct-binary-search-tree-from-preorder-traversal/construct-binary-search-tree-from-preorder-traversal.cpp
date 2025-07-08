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

   TreeNode* helper(vector<int>& preorder,int start,int end,unordered_map<int,int>&store,int & preindex){
        if(start>end)return nullptr;
        int rootval=preorder[preindex++];
        TreeNode* root = new TreeNode(rootval);
        int mid=store[rootval];

        root->left = helper(preorder, start, mid - 1,store,preindex);
        root->right = helper(preorder, mid + 1, end,store,preindex);

        return root;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        for (int i = 0; i < preorder.size(); i++) {
            inorder.push_back(preorder[i]);
        }

        sort(inorder.begin(),inorder.end());
        unordered_map<int,int>store;
       int preindex=0;
       for(int i=0;i<inorder.size();i++){
        store[inorder[i]]=i;

       }
        return helper(preorder,0,inorder.size()-1, store,preindex);
    }


};