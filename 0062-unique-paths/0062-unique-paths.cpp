class Solution {
public:
    int solve(vector<vector<int>>& memo, int x, int y) {
        if (x < 0 || y < 0) return 0;
        if (x == 0 && y == 0) return 1;
        if (memo[x][y] != -1) return memo[x][y];

        memo[x][y] = solve(memo, x - 1, y) + solve(memo, x, y - 1);
        return memo[x][y];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solve(memo, m - 1, n - 1);
    }
};
