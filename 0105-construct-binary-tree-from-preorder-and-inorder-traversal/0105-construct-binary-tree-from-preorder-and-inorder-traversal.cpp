class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;  
        }

        int preorderIndex = 0;
        return buildTree(preorder, inorder, 0, inorder.size() - 1, preorderIndex, mp);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end, int& preorderIndex, unordered_map<int, int>& mp) {
        if (start > end) return nullptr;

        TreeNode* node = new TreeNode(preorder[preorderIndex++]);

        int inorderIndex = mp[node->val];

        node->left = buildTree(preorder, inorder, start, inorderIndex - 1, preorderIndex, mp);
        node->right = buildTree(preorder, inorder, inorderIndex + 1, end, preorderIndex, mp);

        return node;
    }
};