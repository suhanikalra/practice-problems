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
void sortedArray( TreeNode* root, vector<int>& inorder){
    if( root==NULL)return ;
    sortedArray(root->left,inorder);
    inorder.push_back( root->val);
    sortedArray(root->right,inorder);
}

TreeNode* makeTree(int start,int end,vector<int>& inorder){
if( start>end)return NULL;
int mid= ( start+(end-start)/2);
TreeNode* node= new TreeNode(inorder[mid]);
node->left= makeTree( start,mid-1,inorder);
node->right= makeTree( mid+1,end,inorder);

return node;
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
       sortedArray( root,inorder);
      return  makeTree(0, inorder.size()-1,inorder);


    }
};