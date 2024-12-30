class Solution {
public:
    int solve(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int lh = solve(root->left);
        int rh = solve(root->right);
        
        return max(lh, rh) + 1;
    }
    
    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};