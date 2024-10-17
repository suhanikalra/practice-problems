class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       
        vector<vector<pair<int, int>>> graph(n);
        for (auto& it : flights) {
            graph[it[0]].push_back({it[1], it[2]});
        }

        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {src, 0}});

      
        vector<vector<int>> cost(n, vector<int>(k + 2, INT_MAX));
        cost[src][0] = 0; 

        while (!pq.empty()) {
            auto ele = pq.top();
            pq.pop();

            int currentCost = ele.first;
            int currentCity = ele.second.first;
            int stops = ele.second.second;

           
            if (currentCity == dst) {
                return currentCost;
            }

           
            if (stops > k) {
                continue;
            }

           
            for (auto neighbor : graph[currentCity]) {
                int nextCity = neighbor.first;
                int nextCost = neighbor.second;

                int totalCost = currentCost + nextCost;

              
                if (totalCost < cost[nextCity][stops + 1]) {
                    cost[nextCity][stops + 1] = totalCost;  
                    pq.push({totalCost, {nextCity, stops + 1}});
                }
            }
        }

        return -1; 
    }
};
