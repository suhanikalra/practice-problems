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
int i=0;
TreeNode* solve(int start,int end,vector<int>& preorder,unordered_map<int,int>&inordermap){
    if( start>end)return NULL;
    
    int preelement=preorder[i++];
    int mid= inordermap[preelement];
    TreeNode* root= new TreeNode(preelement);
    root->left= solve(start, mid-1,preorder, inordermap);
    root->right=solve(mid+1, end,preorder, inordermap);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inordermap;
        for( int i=0;i<inorder.size();i++){
            inordermap[inorder[i]]=i;
        }
       return solve(0, preorder.size()-1,preorder, inordermap);
    }
};