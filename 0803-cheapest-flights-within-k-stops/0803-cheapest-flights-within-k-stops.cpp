class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create a graph using an adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (auto& it : flights) {
            graph[it[0]].push_back({it[1], it[2]});
        }

        // Priority queue to store (total cost, city, stops)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {src, 0}});  // Starting with source city and 0 cost

        // Array to store the minimum cost to reach each city with at most k stops
        vector<vector<int>> cost(n, vector<int>(k + 2, INT_MAX));
        cost[src][0] = 0;  // Cost to reach the source city with 0 stops

        while (!pq.empty()) {
            auto ele = pq.top();
            pq.pop();

            int currentCost = ele.first;
            int currentCity = ele.second.first;
            int stops = ele.second.second;

            // If we reached the destination city, return the current cost
            if (currentCity == dst) {
                return currentCost;
            }

            // If the number of stops exceeds k, skip this path
            if (stops > k) {
                continue;
            }

            // Explore the neighbors
            for (auto neighbor : graph[currentCity]) {
                int nextCity = neighbor.first;
                int nextCost = neighbor.second;

                int totalCost = currentCost + nextCost;

                // Check if we found a cheaper cost to reach nextCity with stops + 1
                if (totalCost < cost[nextCity][stops + 1]) {
                    cost[nextCity][stops + 1] = totalCost;  // Update cost for the next city with stops + 1
                    pq.push({totalCost, {nextCity, stops + 1}});
                }
            }
        }

        return -1;  // If no path is found within k stops
    }
};
