class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> temp;
        temp.push(root);

        while(!temp.empty()){
            int l = temp.size();
            int val;

            for(int i = 0; i < l; i++){
                TreeNode* node = temp.front();
                temp.pop();
                val = node->val;

                if(node->left != NULL) temp.push(node->left);
                if(node->right != NULL) temp.push(node->right);
            }

            ans.push_back(val);
        }

        return ans;
    }
};