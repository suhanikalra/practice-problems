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
void solve(TreeNode* root,vector<pair<int,TreeNode*>>&vec){
    if(root==nullptr)return ;
   
    solve(root->left,vec);
    vec.push_back({root->val,root});
    solve(root->right,vec);

}
    void recoverTree(TreeNode* root) {
     vector<pair<int,TreeNode*>>vec ;
     solve(root,vec);
     auto t=vec;
     sort(t.begin(),t.end());
     vector<TreeNode*>p;
     for(int i= 0;i<vec.size();i++){
        if(vec[i].first!=t[i].first){p.push_back(vec[i].second);}

     }
     swap(p[0]->val,p[1]->val);
    }
};