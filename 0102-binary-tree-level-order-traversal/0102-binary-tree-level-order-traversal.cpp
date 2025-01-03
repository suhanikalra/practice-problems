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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
          queue<TreeNode*>q;
        q.push(root);
        vector<int> level;
        vector<vector<int>> ans;
        while(!q.empty()){
           int size= q.size();
            
            while(size--){
                auto ele=q.front();
                q.pop();
                level.push_back(ele->val);
                if(ele->left){q.push(ele->left);}
                if(ele->right){q.push(ele->right);}

            }
           
            ans.push_back(level);
            level.clear();
        }
        return ans;
    }
};