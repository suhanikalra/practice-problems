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
void preorder( TreeNode* root,vector<int>&ans){
	if(root==NULL)return;
	ans.push_back(root->val);
	preorder(root->left,ans);
	preorder(root->right,ans);
}
void flatten(TreeNode* root) {
    // add your logic here
    if(root==NULL)return;
	vector<int>ans;
	preorder(root,ans);
	if(root->left)root->left= NULL;
	if(root->right)root->right=NULL;
	
	for(int i=1;i<ans.size();i++){
		root->right = new TreeNode(ans[i]);
		root->left=NULL;
		root=root->right;
	}
}
    // void flatten(TreeNode* root) {
    //     if(root==NULL)return ;
    //     stack<TreeNode*>st;
    //     st.push(root);
    //     while(!st.empty()){
    //         auto curr= st.top();
    //         st.pop();

    //         if(curr->right)st.push(curr->right);
    //         if(curr->left)st.push(curr->left);
    //         if(!st.empty())curr->right= st.top();
    //         if(curr->right)curr->left=NULL;
    //     }
        
    
};