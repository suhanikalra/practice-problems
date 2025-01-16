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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};vector<vector<int>>result;
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);int level=0;
       while(!q.empty()){
        int size= q.size();
        for(int i=0;i<size;i++){
            auto ele= q.front();
            ans.push_back(ele->val);
            q.pop();
            if(ele->left){q.push(ele->left);}
            if(ele->right){q.push(ele->right);}
        }
        if(level%2==0){
        result.push_back(ans);}
        else {reverse(ans.begin(),ans.end()); result.push_back(ans);}
        ans.clear();
        cout<<level;
        level++;
       }
return result;
    }
};