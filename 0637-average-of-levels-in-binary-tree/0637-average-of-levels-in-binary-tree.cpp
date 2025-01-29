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
    vector<double> averageOfLevels(TreeNode* root) {
          if(root== NULL)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<double>ans;double sum=0;int count=0;
        while(!q.empty()){
            int size= q.size();
            
            for(int i=0;i<size;i++){
                auto ele= q.front();
               sum+=ele->val;
               count++;
                q.pop();
                if(ele->left)q.push(ele->left);
                if(ele->right)q.push(ele->right);

            }
            ans.push_back(sum/count);
            sum=0;count=0;
        }
        return ans;
    }
};