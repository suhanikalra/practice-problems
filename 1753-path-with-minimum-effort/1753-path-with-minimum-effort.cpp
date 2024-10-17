class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        vector<vector<int>> effort(row, vector<int>(col, INT_MAX));

        pq.push({0, {0, 0}});
        effort[0][0] = 0;

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        while (!pq.empty()) {
            auto ele = pq.top();
            pq.pop();
            
            int currentEffort = ele.first;
            int x = ele.second.first;
            int y = ele.second.second;

            if (vis[x][y]) continue;
            vis[x][y] = true;

            if (x == row - 1 && y == col - 1) {
                return currentEffort;
            }

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newY >= 0 && newX < row && newY < col) {
                    int new_effort = max(currentEffort, abs(heights[newX][newY] - heights[x][y]));

                    if (new_effort < effort[newX][newY]) {
                        effort[newX][newY] = new_effort;
                        pq.push({new_effort, {newX, newY}});
                    }
                }
            }
        }
        return -1;
    }
};
