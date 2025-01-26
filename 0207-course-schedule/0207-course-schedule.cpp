class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
    for(auto& pre : prerequisites) {
        adj[pre[1]].push_back(pre[0]);
    }
    
    
         int n = adj.size();
        vector<int> indegree(n, 0);int i=0;
        for(int i = 0; i < n; i++) {
            for(int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }
        vector<int>ans;
       queue<int> q;
        for(int k = 0; k < n; k++){
            if(indegree[k] == 0) q.push(k);
}
        while(!q.empty()){
            int ele= q.front();
            ans.push_back(ele);
            q.pop();
            for(int k: adj[ele]){
                indegree[k]--;
                if(indegree[k]==0)q.push(k);
            }
        }
    return ans.size() == numCourses;
    
        
    }
};