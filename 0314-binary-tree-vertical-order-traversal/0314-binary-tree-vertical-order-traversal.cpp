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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};

        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        map<int,vector<int>>mp;
        while(!q.empty()){
            int size= q.size();
            for(int i=0;i<size;i++){
                auto ele= q.front();
                q.pop();
                mp[ele.second].push_back(ele.first->val);
                if(ele.first->left){q.push({ele.first->left,ele.second-1});}
                 if(ele.first->right){q.push({ele.first->right,ele.second+1});}
                
            }
        }
        vector<vector<int>>ans;
        for(auto k: mp){
            ans.push_back(k.second);
        }
        return ans;
        
    }
};