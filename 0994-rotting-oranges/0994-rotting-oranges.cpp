class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>, int>> q;
        int fresh = 0;

        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
                if (grid[i][j] == 1) fresh++;
            }
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int ans = 0;

        while (!q.empty()) {
            auto ele = q.front(); 
            q.pop();

            int x = ele.first.first;
            int y = ele.first.second;
            int dist = ele.second;

            ans = max(ans, dist);

            for (int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if (newx >= 0 && newx < n &&
                    newy >= 0 && newy < m &&
                    grid[newx][newy] == 1) {

                    grid[newx][newy] = 2;
                    fresh--;
                    q.push({{newx, newy}, dist + 1});
                }
            }
        }

        return fresh == 0 ? ans : -1;
    }
};
