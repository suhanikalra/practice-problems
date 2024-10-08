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
bool isSame(TreeNode* left, TreeNode* right) {
 if (left == nullptr && right == nullptr) return true;
if (left==nullptr && right !=nullptr )return false;
if (right==nullptr && left !=nullptr )return false;

TreeNode* p= left;
TreeNode* q= right;
        if(p->val == q->val){
      return (isSame(p->left,q->right) && isSame(q->left,p->right));
} 
return false;
}


    bool isSymmetric(TreeNode* root) {
if (root==nullptr) return true;
if (root->left==nullptr && root->right !=nullptr )return false;
if (root->right==nullptr && root->left !=nullptr )return false;

      return isSame(root->left,root->right);
        
    }
};