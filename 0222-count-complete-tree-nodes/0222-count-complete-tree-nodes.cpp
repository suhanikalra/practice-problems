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
    int countNodes(TreeNode* root) {
        //bfs and count levelorder type
        if(root==nullptr)return 0;
        queue<TreeNode*> q;
        q.push(root);
        int count=1;

        while(!q.empty()){
        TreeNode* a= q.front();
        q.pop();
        if(a->left){q.push(a->left);
        count++;}
        if(a->right){q.push(a->right);
         count++;}

        }
        return count;
    }
};