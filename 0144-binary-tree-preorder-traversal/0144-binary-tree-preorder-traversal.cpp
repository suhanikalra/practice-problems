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
//root left right
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        stack<TreeNode*>st;
        vector<int>ans;
        st.push(root);
        while( !st.empty()){
            auto ele= st.top();
            if(ele)ans.push_back(ele->val);
            st.pop();
            if(ele->right)st.push(ele->right);
            if(ele->left)st.push(ele->left);

        }
        return ans;


    }
};