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
  vector<vector<int>> ans;
        if (root==nullptr){return ans;}
bool flag= true;
        queue< TreeNode*> q;
        q.push(root);
      

        while(!q.empty()){
           int s= q.size();
           vector<int> level;
           while(s--){
            auto ele = q.front();
            q.pop();
            level.push_back(ele->val);
        
            if(ele->left != nullptr){
                q.push(ele->left);
             }
             if(ele->right != nullptr){
                q.push(ele->right);
             }
           }if(flag==true){
        ans.push_back(level);
         flag= false;}
       
        else{reverse(level.begin(),level.end());
        ans.push_back(level);
        flag= true;}




        }
        return ans;
    }
};