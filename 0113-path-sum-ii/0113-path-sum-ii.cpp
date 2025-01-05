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
 void solve(TreeNode* root, int targetsum,vector<int>ans,vector<vector<int>> &result) {
        if(root==nullptr)return ;

        targetsum=targetsum-root->val;ans.push_back(root->val);
        if(root->left==nullptr and root->right==nullptr)if (targetsum==0)result.push_back(ans);;
         solve(root->left,targetsum,ans,result) ;  solve(root->right,targetsum,ans,result);
       
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>ans;
        vector<vector<int>> result;
        solve(root,targetSum,ans,result);
        return result;
    }
};