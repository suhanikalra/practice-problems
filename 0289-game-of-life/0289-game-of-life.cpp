class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> directions = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                                          {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        vector<vector<pair<int, int>>> neighborCounts(
            m, vector<pair<int, int>>(n, {0, 0}));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int zero = 0, one = 0;

                for (auto& dir : directions) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        if (board[ni][nj] == 0)
                            zero++;
                        else
                            one++;
                    }
                }

                neighborCounts[i][j] = {zero, one};
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int zero = neighborCounts[i][j].first;
                int one = neighborCounts[i][j].second;

                if (board[i][j] == 1) {
                    if (one < 2 || one > 3) {
                        board[i][j] = 0;
                    }
                } else {
                    if (one == 3) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};
