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
bool isSame(TreeNode*p,TreeNode*q){
    if(!p and !q)return true;
    if(!p || !q)return false;
    if(p->val != q->val)return false;

    return isSame(p->left,q->left) and isSame(p->right ,q->right);
 

}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL and subRoot==NULL)return true;
        if(root==NULL or subRoot==NULL)return false;

        if(isSame(root,subRoot)==true)return true;
        else{
          return isSubtree(root->right,subRoot) ||  isSubtree(root->left,subRoot) ;

        }
        
    }
};