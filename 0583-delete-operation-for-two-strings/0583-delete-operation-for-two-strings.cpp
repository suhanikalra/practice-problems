class Solution {
public:
int solve(string &w1, string &w2,int i, int j,vector<vector<int>> &dp){
    if(i==w1.size() || j== w2.size() )return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(w1[i]==w2[j]) return dp[i][j]=solve(w1,w2,i+1,j+1,dp)+1;
    
    else  return dp[i][j]= max(solve(w1,w2,i+1,j,dp),solve(w1,w2,i,j+1,dp));
}
    int minDistance(string w1, string w2) {
                vector<vector<int>> dp(w1.size(), vector<int>(w2.size(), -1));

       return w1.size()+w2.size()-2*solve(w1,w2,0,0,dp);
    }
};