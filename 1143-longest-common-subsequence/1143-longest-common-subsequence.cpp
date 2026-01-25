class Solution {
public:
int a=0,b=0;
int solve(int i,int j,int m,int n,string &text1, string &text2,vector<vector<int>>&dp ){
    if(i>=m or j>=n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(text1[i]==text2[j]) {  dp[i][j]=1+solve(i+1,j+1,m,n,text1,text2,dp);}
    else { dp[i][j]=max(solve(i,j+1,m,n,text1,text2,dp),solve(i+1,j,m,n,text1,text2,dp));

    }
    return dp[i][j];
}
    int longestCommonSubsequence(string text1, string text2) {
        int m= text1.size();int n= text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       return solve(0,0,m,n,text1,text2,dp);

    }
};