class Solution {
public:
int solve( int i,vector<int>& coins, int amount,vector<vector<int>>&dp){
    if( amount==0)return 0;
    if( i>= coins.size() or amount<0)return 100000;
    if(dp[i][amount]!=-1)return dp[i][amount];
    

    return dp[i][amount]=  min(solve(i,coins,amount-coins[i],dp)+1, solve(i+1,coins,amount,dp));
}
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans= solve( 0,coins,amount,dp);
         return (ans >= 100000) ? -1 : ans;
    }
};