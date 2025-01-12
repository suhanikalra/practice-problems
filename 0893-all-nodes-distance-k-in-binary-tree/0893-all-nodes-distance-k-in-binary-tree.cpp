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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL or target==NULL)return {};
        queue<TreeNode*>q;
        unordered_map<TreeNode*,TreeNode*>parent;

        q.push(root);
        while(!q.empty()){
            int size= q.size();
            for(int i=0;i<size;i++){
                auto ele= q.front();
                q.pop();
                if(ele->left){parent[ele->left]=ele;q.push(ele->left);}
                if(ele->right){parent[ele->right]=ele;q.push(ele->right);}
            }
            
        }
        unordered_set<TreeNode*>visited;
        q.push(target);
        visited.insert(target);
        int count=0;
        while(!q.empty()){
             int size= q.size();
             if(count==k)break;
            for(int i=0;i<size;i++){
                auto ele= q.front();
                q.pop();
                if(ele->left and visited.find(ele->left)==visited.end()){
                    visited.insert(ele->left);q.push(ele->left);
                }
                if(ele->right and visited.find(ele->right)==visited.end()){
                    visited.insert(ele->right);q.push(ele->right);
                }
                if (parent.find(ele) != parent.end() && visited.find(parent[ele]) == visited.end()) {
                    visited.insert(parent[ele]);q.push(parent[ele]);}
                    
                }count++;

        }vector<int>ans;
        while(!q.empty()){
            if(q.front())ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
   
    }
};