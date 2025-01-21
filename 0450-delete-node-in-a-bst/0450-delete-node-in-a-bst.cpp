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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return root;
        if(root->val==key) {
            if(!root->left and !root->right){delete root;return NULL;}
            else if(!root->left ){TreeNode* temp= root->right;return temp;}
            else  if(!root->right ){TreeNode* temp= root->left;return temp;}
              else {
                TreeNode* temp = root->right;
                TreeNode* tempi = root->right;

                while (tempi->left != NULL) {
                    tempi = tempi->left;
                }

                tempi->left = root->left;

                TreeNode* newRoot = root->right;
                delete root;
                return newRoot;
            }
        

        }

       if(root->val>key)root->left=deleteNode(root->left,key);
        else if(root->val<key)root->right=deleteNode(root->right,key);
        return root;
    }
};