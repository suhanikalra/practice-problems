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
        if(root==NULL)return nullptr;
        if(root->val==p->val or root->val==q->val)return root;
       else if((root->val>p->val and root->val<q->val) or (root->val>q->val and root->val<p->val) )return root;
        else if(root->val> p->val and root->val>q->val )return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);

        
    }
};