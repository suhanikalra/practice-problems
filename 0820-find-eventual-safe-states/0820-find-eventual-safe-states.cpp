class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j : graph[i]) {
                adj[j].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(!indegree[i]) q.push(i);
        }

        while(!q.empty()){
            auto ele= q.front();
            q.pop();
            ans.push_back(ele);

            for(auto x: adj[ele]){
                indegree[x]--;
                if(indegree[x]==0){q.push(x);}


            }
        }
          sort(ans.begin(), ans.end());
        return ans;

       

    }
};