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
bool solve(long long mini,long long maxi,TreeNode* root){
    if(root==NULL)return true;
  
    if( root->val<=mini or root->val>=maxi )return false;

    return solve(mini,root->val,root->left) and solve(root->val,maxi,root->right);
}
    bool isValidBST(TreeNode* root) {
       
        return solve(LONG_MIN, LONG_MAX,root);
        
    }
};