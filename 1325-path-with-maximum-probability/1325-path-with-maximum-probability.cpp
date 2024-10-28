class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].emplace_back(v, prob);
            adj[v].emplace_back(u, prob);
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;

        while (!pq.empty()) {
            double currentProb = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == end_node) {
                return currentProb;
            }

            if (currentProb < maxProb[node]) {
                continue;
            }

            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;
                double newProb = currentProb * edgeProb;

                if (newProb > maxProb[nextNode]) {
                    maxProb[nextNode] = newProb;
                    pq.push({newProb, nextNode});
                }
            }
        }

        return 0.0;
    }
};
