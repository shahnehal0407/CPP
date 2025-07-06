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
    int findBottomLeftValue(TreeNode* root) {
           vector<int> res;


        // map<HorizontalDistance, NodeValue>
        map<int, int> topNode;
        // queue stores pair: (node, horizontalDistance)
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int hd = q.front().second;
            q.pop();


          
                topNode[hd] = node->val;

            if (node->right) q.push({node->right, hd + 1});
            if (node->left) q.push({node->left, hd + 1});

        }

        // collect results from leftmost to rightmost hd
        for (auto it : topNode) {
            res.push_back(it.second);
        }

        return   res[res.size()-1];


    }
};