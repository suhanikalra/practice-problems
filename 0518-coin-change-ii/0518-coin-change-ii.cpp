class Solution {
public:
int solve(int i,int n,int amount, vector<int>& coins,vector<vector<int>>&dp){
    if(i==coins.size())return 0;
    if(amount<0)return 0;
    if(amount==0)return 1;
    if( dp[i][amount]!=-1)return dp[i][amount];
    return dp[i][amount]=solve(i,n,amount-coins[i],coins,dp)+ solve(i+1,n,amount,coins,dp);
}
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(0,n,amount,coins,dp);
    }
};