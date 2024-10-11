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
        
         queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp = nullptr;
        map<TreeNode*, TreeNode*> mp; 

        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                q.push(node->left);
                mp[node->left] = node; 
            }
            
            if (node->right) {
                q.push(node->right);
                mp[node->right] = node;
            }
        }

        
        //bfs on the treeee
        set<TreeNode*>visited;
        queue<TreeNode*> que;
        que.push(target);
        visited.insert(target);
int count=0;
        while(!que.empty()){
            if (count==k)break;
           
           
             int size= que.size();
            for(int i=0;i<size;i++){ auto ele= que.front();
            que.pop();
            if(ele and ele->left and visited.find(ele->left)==visited.end()){ que.push(ele->left);
            visited.insert(ele->left);}
             if(ele and ele->right and visited.find(ele->right)==visited.end()){ que.push(ele->right);
             visited.insert(ele->right);}
             if(visited.find(mp[ele])==visited.end()){que.push(mp[ele]);
             visited.insert(mp[ele]);}
        }
        count++;

        }


vector<int> result;
        while (!que.empty() and que.front() !=nullptr) {
            result.push_back(que.front()->val);
            que.pop();
        }
        
     
     return result;

    }
};