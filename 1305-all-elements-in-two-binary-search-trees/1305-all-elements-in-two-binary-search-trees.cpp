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
vector<int>merge(vector<int>&a,vector<int>&b ){
    int n= a.size();int m= b.size();int i=0,j=0;
    vector<int>res;
    while( i<n and j<m){
        if( a[i]>b[j]){
            res.push_back( b[j++]);
        }
        else{
            res.push_back( a[i++]);
        }
    }
    while( i<n)res.push_back( a[i++]);
    while(j<m)res.push_back( b[j++]);
    return res;
}
void inorder(TreeNode* root,vector<int>&ans){
    if( root==NULL)return ;
    inorder( root->left,ans);
    ans.push_back( root->val);
    inorder( root->right,ans);
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1,ans2;
        inorder(root1,ans1);
        inorder( root2,ans2);
        return merge( ans1,ans2);
    }
};