class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        // Min-heap priority queue
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> effort(row, vector<int>(col, INT_MAX));

        // Initialize starting point with 0 effort
        pq.push({0, {0, 0}});
        effort[0][0] = 0;

        // Directions for moving up, left, down, right
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        while (!pq.empty()) {
            auto ele = pq.top();
            pq.pop();
            int currentEffort = ele.first;
            int X = ele.second.first;
            int Y = ele.second.second;

            // If we reach the bottom-right cell, return the effort
            if (X == row - 1 && Y == col - 1) {
                return currentEffort;
            }

            // Explore the neighbors
            for (int i = 0; i < 4; i++) {
                int newX = X + dx[i];
                int newY = Y + dy[i];

                // Check bounds
                if (newX >= 0 && newY >= 0 && newX < row && newY < col) {
                    // Calculate the new effort required to reach this cell
                    int newEffort = max(currentEffort, abs(heights[newX][newY] - heights[X][Y]));

                    // Only proceed if the new effort is less than what we've recorded
                    if (newEffort < effort[newX][newY]) {
                        effort[newX][newY] = newEffort;  // Update effort for this cell
                        pq.push({newEffort, {newX, newY}});  // Push to priority queue (fixed the missing semicolon)
                    }
                }
            }
        }

        return -1;  // Should not happen in this problem, but good for robustness
    }
};
