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
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true; 

        bool aq = true; 
        queue<TreeNode*> q;
        int totalNodes = 0, level = 0;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* ele = q.front();
                totalNodes++;
                q.pop();

               
                if (ele->left) {
                    if (!aq) return false;
                    q.push(ele->left);
                } else {
                    aq = false; 
                }

               
                if (ele->right) {
                    if (!aq) return false; 
                    q.push(ele->right);
                } else {
                    aq = false; 
                }
            }
            level++;
        }

        return true;
    }
};
