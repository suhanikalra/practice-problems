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
int ans=0;
void solve(TreeNode* root,int dir,int count ){
    if( root==NULL)return;
   
ans= max(count,ans);
    if( dir==0  ){
        solve( root->right,1,count+1);
        solve( root->left,0,1);
    }
    if( dir==1){
        solve( root->left,0,count+1);
   solve( root->right,1,1);
    }

}
    int longestZigZag(TreeNode* root) {
        if(!root)return 0;
       
            solve(root, 0, 0);   // first move left
       
            return ans;
        
    }
};