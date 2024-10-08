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


    bool isSimilar(TreeNode* p, TreeNode* q){
if(!p and !q)return true;
if(!p || !q)return false;
if(p->val!=q->val)return false;

return isSimilar(p->left,q->left) && isSimilar(p->right,q->right);

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr){return false;}
        if(isSimilar( root,  subRoot)){
            return true;
        }
        else{
            return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);

        }
        
    }
};