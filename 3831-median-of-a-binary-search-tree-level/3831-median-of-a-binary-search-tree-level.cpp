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
    int levelMedian(TreeNode* root, int level) {
        queue<TreeNode*> q;
        q.push(root);
        int cur_level = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> values(n);
            for (int i = 0; i < n; i++) {
                auto nxt = q.front();
                q.pop();
                values[i] = nxt->val;
                if (nxt->left)
                    q.push(nxt->left);
                if (nxt->right)
                    q.push(nxt->right);
            }
            if (cur_level++ == level) {
                
                return values[n / 2];
            }
        }
        return -1;
    }
};