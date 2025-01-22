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
void solve(TreeNode* root,vector<TreeNode*>& ans){
    if(root==NULL)return;
ans.push_back(root);
solve(root->left,ans);
solve(root->right,ans);

}
    void flatten(TreeNode* root) {
    vector<TreeNode*>ans;
    solve(root,ans);
    TreeNode* dumm= root;
    for(int i=1;i<ans.size();i++){
        dumm->left=NULL;
        dumm->right=ans[i];
        dumm=ans[i];
    }
  
        
    }
};