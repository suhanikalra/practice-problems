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
private:
    int totalTilt = 0;

    int calculateTilt(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftSum = calculateTilt(root->left);
        int rightSum = calculateTilt(root->right);
        totalTilt += abs(leftSum - rightSum);

        return root->val + leftSum + rightSum;
    }

public:
    int findTilt(TreeNode* root) {
        calculateTilt(root);
        return totalTilt;
    }
};
