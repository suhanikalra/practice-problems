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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
       vector<int> res;
        

        while(root!=nullptr || !st.empty()){
            while(root!=nullptr){
                st.push(root);
                root= root->left;
            }
            root= st.top();
            st.pop();
            res.push_back(root->val);
            root=root->right;
        }
        return res;
        
    }
};