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
  
    TreeNode* solve(int l, int h, vector<int>& v)
    {
        if(l>h) return nullptr;

        int i = max_element (v.begin()+l, v.begin()+h+1) - v.begin();

        TreeNode* a=new TreeNode(v[i]);
        a->left=solve(l,i-1,v);
        a->right=solve(i+1,h,v);
        return a;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& v) {
        return solve(0,v.size()-1,v);
    }

};