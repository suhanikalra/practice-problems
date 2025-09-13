class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        vector<int> state(n, 0); 
        return dfs(source, destination, adj, state);
    }

    bool dfs(int node, int dest, vector<vector<int>>& adj, vector<int>& state) {
        if (state[node] != 0) return state[node] == 2;

        if (adj[node].empty()) return node == dest;

        state[node] = 1; 
        for (int nbr : adj[node]) {
            if (state[nbr] == 1) return false; 
            if (!dfs(nbr, dest, adj, state)) return false;
        }

        state[node] = 2; 
        return true;
    }
};
