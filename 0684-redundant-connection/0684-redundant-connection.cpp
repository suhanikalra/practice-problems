class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        vector<int> indegree(n + 1, 0);
        queue<int> q;

      
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

       
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }

        unordered_set<int> s;

       
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            s.insert(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 1) {
                    q.push(neighbor);
                }
            }
        }

        
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            if (s.find(edges[i][0]) == s.end() && s.find(edges[i][1]) == s.end()) {
                return edges[i];  
            }
        }

        return {};
    }
};
