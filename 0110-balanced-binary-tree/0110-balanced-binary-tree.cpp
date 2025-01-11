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
int height(TreeNode* root,int &ans){
    if(root==NULL)return 0;
    int lh= height(root->left,ans);
    int rh= height(root->left,ans);
    if ( abs(lh-rh)>1){ans=false;return 0;}
    return max(lh,rh)+1;


}
    bool isBalanced(TreeNode* root) {
        int ans=true;
        height(root,ans);
        return ans;
    }
};