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
    int solve(vector<int>& arr) {
        int size = arr.size();
        int count = 0;

        for (int i = 0; i < size; i++) {  
            auto maxIt = max_element(arr.begin(), arr.end() - i);
            int maxIndex = distance(arr.begin(), maxIt);

         
            if (arr[maxIndex] != arr[size - 1 - i]) {
                swap(arr[maxIndex], arr[size - 1 - i]);
                count++;
            }
        }

        return count;
    }

    int minimumOperations(TreeNode* root) {
        if (root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int c = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> ans; 

            for (int i = 0; i < size; i++) {
                auto ele = q.front();
                q.pop();

                if (ele->left) {
                    q.push(ele->left);
                    ans.push_back(ele->left->val);
                }
                if (ele->right) {
                    q.push(ele->right);
                    ans.push_back(ele->right->val);
                }
            }

            if (!ans.empty()) {
                c += solve(ans);
            }
        }

        return c;
    }
};
