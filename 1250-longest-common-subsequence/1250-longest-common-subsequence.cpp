class Solution {
public:

int solve(string &text1, string &text2,int i,int j, vector<vector<int>>&dp){
    if(i>=text1.size() or j>=text2.size()){return 0; }
     if(dp[i][j]!=-1)return dp[i][j];
    if(text1[i]==text2[j]){return solve(text1,text2,i+1,j+1,dp)+1;}
    
    else return dp[i][j]= max(solve(text1,text2,i,j+1,dp),solve(text1,text2,i+1,j,dp));
        
    
}
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return solve(text1,text2,0,0,dp);
    }
};