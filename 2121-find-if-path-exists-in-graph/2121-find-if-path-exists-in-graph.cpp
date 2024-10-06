class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Step 1: Create the adjacency list
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Step 2: Use BFS to find the path
        queue<int> q;
        q.push(source);
        unordered_set<int> visited;

        // Start BFS traversal
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // If we reach the destination, return true
            if (node == destination) return true;

            // Mark the node as visited
            visited.insert(node);

            // Visit all adjacent nodes
            for (int neighbor : graph[node]) {
    if (visited.find(neighbor) == visited.end()) {
        visited.insert(neighbor);  // Mark as visited immediately
        q.push(neighbor);
    }
            }
        }

        // If no path is found, return false
        return false;
    }
};