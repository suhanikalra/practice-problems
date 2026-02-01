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
    int count = 0;
    unordered_map<long long, int> mp;

    void dfs(TreeNode* root, int targetSum,long long currsum ){
        if( root==NULL)return;

        currsum+=root->val;
        if (currsum == targetSum) count++;
        
        if (mp.count(currsum - targetSum))
            count += mp[currsum - targetSum];

        mp[currsum]++;

        dfs( root->left,targetSum,currsum);
        dfs( root->right,targetSum,currsum);

        mp[currsum]--;
    }




    int pathSum(TreeNode* root, int targetSum) {
        if( !root)return 0;
        dfs(root, targetSum,0);
        return count;

        
    }
};