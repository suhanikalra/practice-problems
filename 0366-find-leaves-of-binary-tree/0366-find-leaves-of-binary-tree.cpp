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
map<int,vector<int>>mp;
int solve(TreeNode* root){
     if(root==NULL)return 0;
        auto lh= solve(root->left);
        auto rh= solve(root->right);
        auto k= max(lh,rh)+1;
        mp[k].push_back(root->val);
        return k;
}
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(root==NULL)return {};
        solve(root);
        vector<vector<int>>ans;
        for(auto &k: mp){
            ans.push_back(k.second);
            
        }


       return ans;
        
    }
};