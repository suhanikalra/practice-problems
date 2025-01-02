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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root==nullptr)return ans;
        queue<TreeNode*>q;
        
        q.push(root);
        int level=0;
        while(!q.empty()){
            auto aaaa= q.size();
            while(aaaa--){
            auto ele= q.front();
            
            if(aaaa==0)ans.push_back(ele->val);
            q.pop();
            
            if(ele->left) q.push(ele->left);
            if(ele->right)q.push(ele->right);
             
            }
            


        }
return ans;
        
    }
};