/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;
    void solve(TreeNode* root, int targetSum, vector<int> ans) {
        if (root == NULL)
            return;
        
        ans.push_back(root->val);
        if (root->left == NULL && root->right == NULL &&
            targetSum == root->val) {
            res.push_back(ans);
            return;
        }
        solve(root->left, targetSum - root->val, ans);
        solve(root->right, targetSum - root->val, ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return {};
        vector<int> ans;
        solve(root, targetSum, ans);
        return res;
    }
};