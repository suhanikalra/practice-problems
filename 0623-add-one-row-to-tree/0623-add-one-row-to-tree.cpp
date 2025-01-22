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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
           TreeNode* newRoot = new TreeNode(val);
            newRoot->left=root;
            return newRoot;


        }
        queue<TreeNode*>q;int currentDepth=1;
        q.push(root);
        while(!q.empty()){
            
            int size= q.size();

            if (currentDepth == depth - 1) {
                for (int i = 0; i < size; i++) {
                    TreeNode* current = q.front();
                    q.pop();
                    
                    TreeNode* originalLeft = current->left;
                    TreeNode* originalRight = current->right;
                    
                    current->left = new TreeNode(val);
                    current->right = new TreeNode(val);
                    
                    current->left->left = originalLeft;
                    current->right->right = originalRight;
                }
                break;  
            }
            
            for(int i= 0;i<size;i++){
                auto ele=q.front();q.pop();
              
                if(ele->left)q.push(ele->left);
                if(ele->right)q.push(ele->right);
            }
           currentDepth++;
        }return root;
    }
};