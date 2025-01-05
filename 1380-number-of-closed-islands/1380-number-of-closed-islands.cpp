class Solution {
public:
    void solve(vector<vector<int>>& grid, int i, int j, vector<int> dx,
               vector<int> dy) {
                if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || grid[i][j] !=0 )return;
        if (grid[i][j] == 0)
            grid[i][j] = 1;
        for (int index = 0; index < 4; index++) {
          solve(grid, i + dx[index], j + dy[index], dx, dy);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][0] == 0)
                solve(grid, i, 0, dx, dy);
            if (grid[i][grid[0].size() - 1] == 0)
                solve(grid, i, grid[0].size() - 1, dx, dy);
        }

        for (int i = 0; i < grid[0].size(); i++) {
            if (grid[0][i] == 0)
                solve(grid, 0, i, dx, dy);
            if (grid[grid.size() - 1][i] == 0)
                solve(grid, grid.size() - 1, i, dx, dy);
        }
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    solve(grid, i, j, dx, dy);
                    count++;
                }
            }
        }
        return count; 
    }
};