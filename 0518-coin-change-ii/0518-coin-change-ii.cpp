class Solution {
public:
int solve(int amount, vector<int>& coins,int ans, int i,  vector<vector<int>>&dp){
    if(ans==amount)return 1;
    if(ans>amount)return 0;
    if(i>=coins.size())return 0;
    if(dp[i][ans ]!= -1)return dp[i][ans];

     dp[i][ans]=solve(amount,coins,ans+coins[i],i,dp)+solve(amount,coins,ans,i+1,dp);
     return dp[i][ans];
}
    int change(int amount, vector<int>& coins) {
                vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

      return  solve(amount, coins, 0,0,dp );
        
    }
};