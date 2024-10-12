class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& memo) {
        if (i >= grid.size() || j >= grid[0].size()) return INT_MAX;
        if (i == grid.size() - 1 && j == grid[0].size() - 1) return grid[i][j];
        
        if (memo[i][j] != -1) return memo[i][j];

        int down = solve(grid, i + 1, j, memo);
        int right = solve(grid, i, j + 1, memo);

        memo[i][j] = grid[i][j] + min(down, right);
        return memo[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return solve(grid, 0, 0, memo);
    }
};
