/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> ind;
        for (int i = 0; i < inorder.size(); i++) {
            ind[inorder[i]] = i;
        }
        int preorderInd = 0;
        return buildTreeHelper(preorder, inorder, ind, 0, inorder.size() - 1,
                               preorderInd);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,
                              unordered_map<int, int>& ind, int inorderStart,
                              int inorderEnd, int& preorderInd) {

        if (inorderStart > inorderEnd) {
            return nullptr;
        }

        int rootVal = preorder[preorderInd++];
        TreeNode* root = new TreeNode(rootVal);

        int inorderIndex = ind[rootVal];

        root->left = buildTreeHelper(preorder, inorder, ind, inorderStart,
                                     inorderIndex - 1, preorderInd);
        root->right = buildTreeHelper(preorder, inorder, ind, inorderIndex + 1,
                                      inorderEnd, preorderInd);

        return root;
    }
};
