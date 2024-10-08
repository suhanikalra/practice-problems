/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (cloned== nullptr) return nullptr;
        if (cloned->val== target->val) return cloned;

        TreeNode* leftResult = getTargetCopy(original, cloned->left, target);
        if (leftResult != nullptr) return leftResult;  
        if (cloned->right != nullptr){ return getTargetCopy(original,  cloned->right, target);}

        return nullptr;
        

    }
};