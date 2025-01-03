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
TreeNode* ins(TreeNode* root,int val){
        if(root==NULL){TreeNode* rooti= new TreeNode(val);return rooti;}
        if(root->val>val)root->left=insertIntoBST(root->left,val);
        if(root->val<val)root->right=insertIntoBST(root->right,val);
        return root;
}
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return ins(root,val);
       


    }
};