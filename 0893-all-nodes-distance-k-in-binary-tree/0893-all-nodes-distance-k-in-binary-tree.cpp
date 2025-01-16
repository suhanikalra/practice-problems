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
        
        unordered_map<TreeNode*,TreeNode*>mp;
        queue<TreeNode*>q;int level=0;
        q.push(root);
        while(!q.empty()){
            int size= q.size();
            for(int i=0;i<size;i++){
                auto ele= q.front();
                q.pop();
                if(ele->left){mp[ele->left]=ele;q.push(ele->left);}
                if(ele->right){mp[ele->right]=ele;q.push(ele->right);}
            }
        }
unordered_set<TreeNode*>visited;
visited.insert(target);
q.push(target);
         while(!q.empty()){
            int size= q.size();
            if( level==k)break;
            for(int i=0;i<size;i++){
                auto ele= q.front();q.pop();
                
                if(ele->left and visited.find(ele->left)==visited.end()){
                    q.push(ele->left);   visited.insert(ele->left);  
                }
                if(ele->right and visited.find(ele->right)== visited.end() ){
                    q.push(ele->right);     visited.insert(ele->right);
                }
                if (mp.find(ele) != mp.end() && visited.find(mp[ele]) == visited.end()) {
    q.push(mp[ele]);
    visited.insert(mp[ele]);
}
            }level++;
         }
vector<int>ans;
        while(!q.empty()){
            if(q.front())ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};