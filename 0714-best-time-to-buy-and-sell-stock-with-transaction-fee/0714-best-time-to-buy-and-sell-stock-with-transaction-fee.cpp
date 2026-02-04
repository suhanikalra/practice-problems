class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int buy, int fee, vector<int>& prices) {
        if (i == prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        if (buy) {
           
            return dp[i][buy] = max(
                -prices[i] + solve(i + 1, 0, fee, prices),
                solve(i + 1, 1, fee, prices)
            );
        } else {
          
            return dp[i][buy] = max(
                prices[i] - fee + solve(i + 1, 1, fee, prices),
                solve(i + 1, 0, fee, prices)
            );
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        dp = vector<vector<int>>(n, vector<int>(2, -1));
        return solve(0, 1, fee, prices);
    }
};
