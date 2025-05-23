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
void solve(TreeNode* root,vector<int>&ans){
    if(root==NULL)return ;
    solve(root->left,ans);

    solve(root->right,ans);
            if(root->left==nullptr and root->right==nullptr)ans.push_back(root->val);


}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1; vector<int>ans2;
        solve(root1,ans1);
         solve(root2,ans2);
         return ans1==ans2;
       

    }
};