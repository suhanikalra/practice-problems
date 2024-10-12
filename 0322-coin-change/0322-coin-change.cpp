class Solution {
public:
    int solve(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (amount < 0 || i >= coins.size()) return INT_MAX;

        if (dp[i][amount] != -1) return dp[i][amount];

        int include = INT_MAX;
        if (amount >= coins[i]) {
            include = solve(coins, amount - coins[i], i, dp);
            if (include != INT_MAX) include += 1;
        }
        
        int exclude = solve(coins, amount, i + 1, dp);

        return dp[i][amount] = min(include, exclude);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int result = solve(coins, amount, 0, dp);
        return (result == INT_MAX) ? -1 : result;
    }
};
