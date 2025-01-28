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
    vector<int> largestValues(TreeNode* root) {
        if(root== NULL)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            int size= q.size();
            int maxi=INT_MIN;
            for(int i=0;i<size;i++){
                auto ele= q.front();
                if(ele)maxi= max(maxi,ele->val);
                q.pop();
                if(ele->left)q.push(ele->left);
                if(ele->right)q.push(ele->right);

            }
            ans.push_back(maxi);
        }
        return ans;
    }
};