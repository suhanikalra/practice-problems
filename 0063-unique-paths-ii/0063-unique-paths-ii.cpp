class Solution {

public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp,vector<vector<int>>& grid) {
        if (i >= m or j >= n)return 0;
        if (grid[i][j] == 1)return 0;
        if (i == m - 1 and j == n - 1 and grid[i][j]!=1)return 1;
       
        if (dp[i][j] != -1)return dp[i][j];
        return dp[i][j] = solve(i + 1, j, m, n, dp, grid) + solve(i, j + 1, m, n, dp, grid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0]==1 or grid[m-1][n-1]==1)return 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(0, 0, m, n, dp, grid);
    }
};