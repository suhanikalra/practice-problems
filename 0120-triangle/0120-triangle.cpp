class Solution {
public:
    int solve(vector<vector<int>>& triangle, int i, int j,
              vector<vector<int>>& dp) {
        if (i == triangle.size() - 1)
            return triangle[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = min(solve(triangle, i + 1, j, dp),
                              solve(triangle, i + 1, j + 1, dp)) +
                          triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(triangle, 0, 0, dp);
    }
};