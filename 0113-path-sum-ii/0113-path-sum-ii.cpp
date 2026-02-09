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
   vector<vector<int>>ans;

   void solve(TreeNode* root, int targetSum,vector<int>res){
    if(root==NULL)return;
    targetSum-=root->val;
    res.push_back( root->val);

    if( root->left==NULL and root->right==NULL and targetSum==0){
        ans.push_back( res);
    }
     solve( root->left,targetSum,res);
      solve( root->right,targetSum,res);
   }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if( root==NULL)return {};
        vector<int>res;
        solve( root,targetSum,res);
        return ans;

    }
};