class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp, int m, int n,
              vector<vector<int>>& obstacleGrid) {

        if (i >= m or j >= n)
            return 0;
        if (obstacleGrid[i][j] == 1)
            return 0;
        if (i == m - 1 and j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = solve(i + 1, j, dp, m, n, obstacleGrid) +
                          solve(i, j + 1, dp, m, n, obstacleGrid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1)
            return 0;

        return solve(0, 0, dp, m, n, obstacleGrid);
    }
};