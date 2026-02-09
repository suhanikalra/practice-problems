class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* node, bool left, int len) {
        if (!node) return;

        ans = max(ans, len);

        if (left) {
            dfs(node->right, false, len + 1); 
            dfs(node->left, true, 1);       
        } else {
            dfs(node->left, true, len + 1);  
            dfs(node->right, false, 1);      
        }
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        dfs(root->left, true, 1);
        dfs(root->right, false, 1);
        return ans;
    }
};
