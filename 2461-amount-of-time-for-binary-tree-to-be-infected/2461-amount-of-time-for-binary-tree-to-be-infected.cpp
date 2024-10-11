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
    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp = nullptr;
        map<TreeNode*, TreeNode*> mp; 

        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                q.push(node->left);
                mp[node->left] = node; 
            }
            
            if (node->right) {
                q.push(node->right);
                mp[node->right] = node;
            }

            if (node->val == start) {
                temp = node; 
            }
        }
int time = 0;
        queue<TreeNode*> que;
        que.push(temp);
        set<TreeNode*> visited;
        visited.insert(temp);

        while (!que.empty()) {
            int size = que.size();
            bool spread = false;

            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                if (node->left && visited.find(node->left) == visited.end()) {
                    que.push(node->left);
                    visited.insert(node->left);
                    spread = true;
                }

                if (node->right && visited.find(node->right) == visited.end()) {
                    que.push(node->right);
                    visited.insert(node->right);
                    spread = true;
                }

                if (mp.find(node) != mp.end() && visited.find(mp[node]) == visited.end()) {
                    que.push(mp[node]);
                    visited.insert(mp[node]);
                    spread = true;
                }
            }

            if (spread) {
                time++;
            }
        }

        return time;
    }
};