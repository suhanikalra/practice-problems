class Solution {
public:
int solve(string &text1, string &text2,int i,int j, vector<vector<int>>&dp){
    if(i>=text1.size() || j>=text2.size())return 0;
    if(text1[i]==text2[j]) return solve(text1,text2,i+1,j+1,dp)+1;
    if(dp[i][j]!=-1)return dp[i][j];
    else return dp[i][j]= (max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp)));

}
   
    int minInsertions(string s) {
         vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
    string k=s;
    reverse(k.begin(),k.end());
        return s.size()- solve(s,k,0,0,dp); 
    }
};