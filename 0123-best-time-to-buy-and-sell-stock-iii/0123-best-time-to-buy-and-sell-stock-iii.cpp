class Solution {
public:
 vector<vector<vector<int>>> dp;

 int solve(int i, int buy, int k, vector<int>& prices) {
    if( i==prices.size() or k>=2)return 0;
    if (dp[i][buy][k] != -1)
            return dp[i][buy][k];

    if( buy){
         return dp[i][buy][k] = max( -prices[i]+ solve(i+1,0,k,prices),0+solve(i+1,1,k,prices));
    }
    else return dp[i][buy][k] = max(prices[i] + solve(i + 1, 1, k + 1, prices),
                solve(i + 1, 0, k, prices));
 }
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
        dp = vector<vector<vector<int>>>(n,
              vector<vector<int>>(2, vector<int>(3, -1)));
              return solve(0, 1, 0, prices);
    }
};