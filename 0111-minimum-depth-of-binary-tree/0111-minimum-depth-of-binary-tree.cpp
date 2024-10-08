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
    int minDepth(TreeNode* root) {
        if (root==nullptr){return 0;}

        int lefth= minDepth(root->left)+1;
         int righth= minDepth(root->right)+1;

         int k= min(lefth,righth);
         if (k>1)return k;
         else return max(lefth,righth);
    }
};