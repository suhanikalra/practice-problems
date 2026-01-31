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
 TreeNode*ans=NULL;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if( root==NULL or p==NULL)return NULL;
        if( root->val>p->val){ans= root;inorderSuccessor(root->left,p);}
        else{inorderSuccessor(root->right,p);}
        return ans;
        
    }
};