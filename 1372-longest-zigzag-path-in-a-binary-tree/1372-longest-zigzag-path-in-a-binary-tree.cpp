class Solution {
public:
    int maxi = 0;

    void dfs(TreeNode* root, int dir, int len) {
        if (root == NULL) return;

        maxi = max(maxi, len);

        // dir = 0 → last move was left
        // dir = 1 → last move was right

        if (root->left) {
            if (dir == 1)
                dfs(root->left, 0, len + 1); // zigzag continues
            else
                dfs(root->left, 0, 1);       // restart
        }

        if (root->right) {
            if (dir == 0)
                dfs(root->right, 1, len + 1); // zigzag continues
            else
                dfs(root->right, 1, 1);       // restart
        }
    }

    int longestZigZag(TreeNode* root) {
        if (root == NULL) return 0;

        dfs(root, 0, 0); // assume last move was left
        dfs(root, 1, 0); // assume last move was right

        return maxi;
    }
};
