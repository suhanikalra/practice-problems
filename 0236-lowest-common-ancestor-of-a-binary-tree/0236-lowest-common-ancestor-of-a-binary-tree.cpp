/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL)return nullptr;
        if(root->val==p->val or root->val==q->val)return root;
      auto lefti=  lowestCommonAncestor(root->left,p,q);
      auto righti=  lowestCommonAncestor(root->right,p,q);
      if(lefti and righti)return root;
      if(lefti==NULL)return righti;
      if(righti==NULL)return lefti;
        return root;
    }
};