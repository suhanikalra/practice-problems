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
int solve(TreeNode* root, int &ans,int height){
    if( root==NULL)return 0;
    int lh= solve( root->left, ans,height);
    int rh= solve( root->right, ans,height);
    ans= max( lh+rh,ans);
    return max(lh,rh)+1;

}
    int diameterOfBinaryTree(TreeNode* root) {
        if( root==NULL)return 0;
int ans=0;
        solve(root,ans, 0);
        return ans;
    }
};