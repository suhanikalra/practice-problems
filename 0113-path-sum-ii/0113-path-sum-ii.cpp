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
vector<vector<int>>res;
    void solve ( TreeNode* root, int targetSum,vector<int>ans){
        if( root==NULL)return;
        targetSum-=root->val;ans.push_back(root->val);
        if(root->left==NULL and !root->right){
            if( targetSum==0)res.push_back({ ans});
        }
        solve( root->left,targetSum,ans);solve( root->right,targetSum,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>ans;
        solve( root,targetSum,ans);
        return res;

    }
};