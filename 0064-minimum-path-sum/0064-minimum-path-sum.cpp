class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        if(i>=grid.size() ||j>=grid[0].size())return INT_MAX;
        if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
        if(dp[i][j] != -1)return dp[i][j];

      dp[i][j]=  min(solve(grid,i+1,j,dp),solve(grid,i,j+1,dp)) +grid[i][j];
      return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(grid, 0, 0, dp);
    }
};
