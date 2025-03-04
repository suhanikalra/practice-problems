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
void solve(TreeNode *root,int maxi,int &count){
    if(root==NULL)return;
    if(root->val>=maxi){count++;maxi= root->val;}
    solve(root->left,maxi,count);
    solve(root->right,maxi,count);
}
    
    int goodNodes(TreeNode* root) {
        int maxi= root->val;
        int count=0;
        solve(root,maxi,count);
        return count;

    }
};