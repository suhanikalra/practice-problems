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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        vector<int>ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            auto ele= st.top();
            ans.push_back(ele->val);
            st.pop();
            if(ele->right)st.push(ele->right);
            if(ele->left)st.push(ele->left);
        }
        return ans;
        
    }
};