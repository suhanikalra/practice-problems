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
void solve(TreeNode* root,int targetSum,vector<int>&result,vector<vector<int>>&ans){
     if(root==NULL)return ;
        //preorder
        result.push_back(root->val);
        targetSum-=root->val;
        if(root->left==NULL and root->right==NULL and targetSum==0){ans.push_back(result);}

        if(root->left){solve(root->left,targetSum,result,ans);}
        if(root->right){solve(root->right,targetSum,result,ans);}
       result.pop_back();
        
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>result;vector<vector<int>>ans;
       solve(root,targetSum,result,ans);
       return ans;
    }
};