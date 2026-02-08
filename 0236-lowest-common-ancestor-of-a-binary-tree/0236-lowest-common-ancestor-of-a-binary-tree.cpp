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
        if( root==NULL)return NULL;
        if( root==p or root==q)return root;
        auto lefti= lowestCommonAncestor(root->left,p,q);
        auto righti= lowestCommonAncestor(root->right,p,q);
        if( lefti && righti)return root;
        else if(lefti)return lefti;
        return righti;


    }
};