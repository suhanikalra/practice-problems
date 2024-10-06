class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
       if (n == 1) return {0};
         unordered_map<int, vector<int>> graph;
        //create adjacency list
        for(const auto &edge :edges){
            int u= edge[0];
            int v= edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
//identifying the leaves
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) {
                leaves.push_back(i);
            }
        }
    while (n > 2) {
            n -= leaves.size(); // Reduce the number of nodes
            vector<int> newLeaves; // For the next layer of leaves
            
            // Remove current leaves and update the graph
            for (int leaf : leaves) {
                // Get the only neighbor (parent) of the leaf
                int neighbor = graph[leaf][0];
                // Remove the leaf from its neighbor's adjacency list
                graph[neighbor].erase(remove(graph[neighbor].begin(), graph[neighbor].end(), leaf), graph[neighbor].end());
                // If the neighbor becomes a leaf, add it to newLeaves
                if (graph[neighbor].size() == 1) {
                    newLeaves.push_back(neighbor);
                }
            }
            leaves = newLeaves; // Move to the next layer of leaves
        }

        return leaves; // Remaining nodes are the MHT roots
    }
};