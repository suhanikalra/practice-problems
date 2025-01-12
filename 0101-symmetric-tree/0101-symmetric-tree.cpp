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
bool isSimilar(TreeNode* p,TreeNode* q){
    if(p==NULL and q==NULL)return true;
    if(p==NULL or q==NULL)return false;
    if(p->val!= q->val)return false;
    return isSimilar(p->left,q->right) and isSimilar(p->right,q->left);

}
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        if(isSimilar(root->left,root->right)==false)return false;
       return true;

        
    }
};