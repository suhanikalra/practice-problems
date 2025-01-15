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
 ////bye//suno yes-> tumne suppport role ke apply kra tha? nhi-> i can see a maul on kalra ha kia tha kaafi phle kya kru bolo
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL and root2==nullptr )return nullptr;
        if(root1==NULL)return root2;
        if(root2==NULL)return root1;

        if(root1!=NULL and root2!=nullptr ){root1->val=root1->val+root2->val;}
        root1->left=mergeTrees(root1->left,root2->left);
         root1->right=mergeTrees(root1->right,root2->right);
         return root1;
    }
};