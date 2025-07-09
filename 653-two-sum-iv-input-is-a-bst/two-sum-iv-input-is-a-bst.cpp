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
// class Solution {
// public:
//     bool dfs(TreeNode* root, unordered_set<int>& seen, int k) {
//         if (!root) return false;

//         if (seen.count(k - root->val)) return true;

//         seen.insert(root->val);

//         return dfs(root->left, seen, k) || dfs(root->right, seen, k);
//     }

//     bool findTarget(TreeNode* root, int k) {
//         unordered_set<int> seen;
//         return dfs(root, seen, k);
//     }
// };


class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);

        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == k) return true;
            else if (sum < k) left++;
            else right--;
        }

        return false;
    }
};