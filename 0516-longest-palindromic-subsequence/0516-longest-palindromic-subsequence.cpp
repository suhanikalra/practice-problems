class Solution {
public:
int solve(string &s,string &k, int i,int j, vector<vector<int>> &dp){
    if( i== s.size() or j==s.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if( s[i]==k[j]){
        return dp[i][j]=1+solve(s,k,i+1,j+1,dp);
    }

    else return  dp[i][j]= max( solve(s,k,i+1,j,dp),solve(s,k,i,j+1,dp));
}
    int longestPalindromeSubseq(string s) {
          vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
        string k=s;
        string ans="";
        reverse(k.begin(),k.end());
        return solve(s,k,0,0,dp);
    }
};