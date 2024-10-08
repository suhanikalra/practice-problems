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
    void findPaths(TreeNode* node, string path, vector<string>& result) {
        if (!node) return;
        path += to_string(node->val);
        if (!node->left && !node->right) result.push_back(path);
        else {
            path += "->";
            findPaths(node->left, path, result);
            findPaths(node->right, path, result);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        findPaths(root, "", result);
        return result;
    }
};