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
            if(root==NULL)return NULL;
            if(root->val==p->val or q->val==root->val)return root;
            auto l= lowestCommonAncestor(root->left,p,q);
            auto r= lowestCommonAncestor(root->right,p,q);
            if(l==NULL)return r;
            if(!r)return l;
             return root;
        
    }
};