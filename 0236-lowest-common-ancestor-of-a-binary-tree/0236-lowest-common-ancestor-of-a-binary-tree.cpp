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
        if (root==NULL)return NULL;
        if(root->val==q->val or root->val==p->val) return root;
        auto a=lowestCommonAncestor(root->left,p,q);
        auto b=lowestCommonAncestor(root->right,p,q);
        if(!a )return b;
        if(!b)return a;
        return root;
        
    }
};