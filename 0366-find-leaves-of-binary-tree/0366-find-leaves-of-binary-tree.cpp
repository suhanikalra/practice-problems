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
int solve(TreeNode* root,  unordered_map<int,vector<int>>&mp){
    if(root==NULL)return 0;
    int lh= solve(root->left,mp);
    int rh= solve(root->right,mp);

    int height= max(lh,rh)+1;
    mp[height].push_back(root->val);
    return height;
}
    vector<vector<int>> findLeaves(TreeNode* root) {
        unordered_map<int,vector<int>>mp;
        int k=solve(root,mp);
         vector<vector<int>> ans;
        for(int i=1;i<=k;i++){
            ans.push_back(mp[i]);
        }
       
        return ans;
    }
};