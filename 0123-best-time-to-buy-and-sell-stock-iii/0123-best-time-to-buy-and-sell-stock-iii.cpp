class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(int i, int buy, int k, vector<int>& prices) {
        if (i == prices.size() || k == 2)
            return 0;

        if (dp[i][buy][k] != -1)
            return dp[i][buy][k];

        if (buy) {
            return dp[i][buy][k] = max(
                -prices[i] + solve(i + 1, 0, k, prices), // buy
                 solve(i + 1, 1, k, prices)               // skip
            );
        } else {
            return dp[i][buy][k] = max(
                prices[i] + solve(i + 1, 1, k + 1, prices), // sell
                solve(i + 1, 0, k, prices)                  // skip
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp = vector<vector<vector<int>>>(n,
              vector<vector<int>>(2, vector<int>(3, -1)));

        return solve(0, 1, 0, prices);
    }
};
