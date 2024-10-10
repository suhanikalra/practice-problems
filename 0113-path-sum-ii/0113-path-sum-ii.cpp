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
    vector<vector<int>> result;

    void helper(TreeNode* root, int &targetSum, int sum, vector<int>& temp) {
        if (root == nullptr) return;

        sum += root->val;
        temp.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr && sum == targetSum) {
            result.push_back(temp);
        } else {
            helper(root->left, targetSum, sum, temp);
            helper(root->right, targetSum, sum, temp);
        }
        
       
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        helper(root, targetSum, 0, temp);
        return result;
    }
};
