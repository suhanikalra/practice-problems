class Solution {
public:
int solve(int i,int j,string &text1, string &text2,int ans, vector<vector<int>>&dp)   {
    if(i>=text1.length() or j>=text2.size())return 0;
     if(dp[i][j]!=-1)return dp[i][j];
    if(text1[i]==text2[j])return dp[i][j]= solve(i+1,j+1,text1,text2,ans+1,dp)+1;
   
    else return dp[i][j]= max( solve(i+1,j,text1,text2,ans,dp), solve(i,j+1,text1,text2,ans,dp));

}
    int longestCommonSubsequence(string text1, string text2) {
        int ans=0;
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return solve(0,0,text1,text2,ans,dp);
    }
};