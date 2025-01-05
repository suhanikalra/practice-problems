class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2)
                    q.push({{i, j}, 0});
                if (grid[i][j] == 1)
                    fresh++;
            }
        }
        int time = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while (!q.empty()) {

            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto ele = q.front();
                int x = ele.first.first;
                int y = ele.first.second;
                int dist = ele.second;
                q.pop();
                for (int j = 0; j < 4; j++) {
                    auto newx = x + dx[j];
                    int newy = y + dy[j];
                    if (newx >= 0 and newy >= 0 and newx < grid.size() and
                        newy < grid[0].size() and grid[newx][newy] == 1) {
                            grid[newx][newy] = 2;
                        q.push({{newx, newy}, dist + 1});
                        fresh--;
                         time = max(time, dist + 1);
                    }
                }
            }
        }
        if (fresh == 0)
            return time;
        return -1;
    }
};