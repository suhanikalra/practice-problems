class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;

        for (int nbr : adj[node]) {
            if (!vis[nbr]) {
                if (dfs(nbr, node, adj, vis)) return true;
            } else if (nbr != parent) {
                return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);   

        for (auto& e : edges) {
            int u = e[0], v = e[1];

            
            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<bool> vis(n + 1, false);
            if (dfs(u, -1, adj, vis)) {
                return e;  
            }
        }

        return {};
    }
};
