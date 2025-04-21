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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int sum = 0;int ans=0;
        q.push(root);int count=0;
        int maxi = INT_MIN;
        while (!q.empty()) {
            
            int size = q.size();
             sum = 0;
            for (int i = 0; i < size; i++) {
                auto ele = q.front();q.pop();
               sum += ele->val;
                if (ele->left) {
                    q.push(ele->left);
                    }

           if(ele->right){
                        q.push(ele->right);
                       
                    }
                }
            count++;
            if (sum > maxi) {
                ans = count;
                maxi = sum;
            }
           
        }
        return ans;
    }
};