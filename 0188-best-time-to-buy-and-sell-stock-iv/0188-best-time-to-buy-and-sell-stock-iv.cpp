
class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(int i, int buy, int k,int count, vector<int>& prices) {
        if (i == prices.size() || k == count)
            return 0;

        if (dp[i][buy][count] != -1)
            return dp[i][buy][count];

        if (buy) {
            return dp[i][buy][count] = max(
                -prices[i] + solve(i + 1, 0, k,count, prices), // buy
                 solve(i + 1, 1, k,count, prices)               // skip
            );
        } else {
            return dp[i][buy][count] = max(
                prices[i] + solve(i + 1, 1,k, count + 1, prices), 
                solve(i + 1, 0, k,count, prices)                  
            );
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        
    int n = prices.size();
        dp = vector<vector<vector<int>>>(n,
              vector<vector<int>>(2, vector<int>(k, -1)));

        return solve(0, 1, k,0, prices);
}
};