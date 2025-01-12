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
        queue<TreeNode*>q;
        q.push(root);int count=0;
        vector<vector<int>>ans;
        while(!q.empty()){
            int size= q.size();
            vector<int>level;
            count++;
            for(int i=0;i<size;i++){
                auto ele= q.front();
                if(ele)level.push_back(ele->val);
               
                q.pop();
                if(ele->left)q.push(ele->left);
                if(ele->right)q.push(ele->right);
            }
            if(count%2==1)ans.push_back(level);
            else {
                reverse(level.begin(),level.end());
                ans.push_back(level);
            }
           
        }
        return ans;
    }
};