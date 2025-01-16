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
bool issimilar(TreeNode* p, TreeNode* q){
    if(p==NULL and q== NULL)return true;
    if(p==NULL or q== NULL)return false;
    if(p->val!=q->val)return false;
    return issimilar(p->left,q->right) and issimilar(p->right, q->left);

}
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        if(root->left==NULL and root->right==NULL)return true;
        if(root->left==NULL || root->right==NULL)return false;
        return issimilar(root->left,root->right);

    }
};