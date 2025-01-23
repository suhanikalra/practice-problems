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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        queue<TreeNode*>q;bool a= true;vector<vector<int>>res;
        q.push(root);
        while(!q.empty()){
            int size= q.size();
            vector<int>ans;
            
            for(int i= 0;i<size;i++){
                auto ele= q.front();q.pop();ans.push_back(ele->val);
                if(ele->left)q.push(ele->left);
                if(ele->right)q.push(ele->right);
            }
            a=!a;
            if(a==false)res.push_back(ans);
            else{reverse(ans.begin(),ans.end());res.push_back(ans);}

        }
        return res;
        
    }
};