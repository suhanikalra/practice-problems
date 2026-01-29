class Solution {
public:
    int inorderSum = 0;

    

    TreeNode* bstToGst(TreeNode* root) {
        
        if( root==NULL)return NULL;
         bstToGst(root->right);
         inorderSum+=root->val;
         root->val=inorderSum;
         bstToGst(root->left);
         return root;
    }
};
