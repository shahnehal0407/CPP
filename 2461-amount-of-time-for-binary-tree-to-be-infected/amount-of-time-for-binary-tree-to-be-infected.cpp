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
    void mark_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent,TreeNode*& startNode, int start){

queue<TreeNode*>q;
q.push(root);
while(!q.empty()){
    TreeNode* curr=q.front();
    q.pop();
    if (curr->val == start)
        startNode = curr;
    if(curr->left){
        parent[curr->left]=curr;
        q.push(curr->left);
    }
        if(curr->right){
        parent[curr->right]=curr;
        q.push(curr->right);
    }
}
  }


    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent;
        TreeNode* startNode;
        mark_parent(root,parent,startNode,start);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
                q.push(startNode);
        visited[startNode]=true;
        int curr_level=-1;
        while(!q.empty()){
            int size=q.size();
           curr_level++;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;

                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;

                }
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]]=true;

                }

            }
        }

        return curr_level;

        
    }
};