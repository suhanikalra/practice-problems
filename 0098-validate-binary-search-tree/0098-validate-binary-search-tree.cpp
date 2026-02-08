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
bool isValid(long long mini, long long maxi, TreeNode* root){
    if(root==NULL)return true;
    if( root->val<=mini or root->val>=maxi)return false;
    return isValid( mini,root->val,root->left) and isValid( root->val,maxi,root->right);
}
    bool isValidBST(TreeNode* root) {
        if( root==NULL)return true;
        return isValid( LLONG_MIN,LLONG_MAX,root);
    }
};