class Solution {
public:
bool solve( int i,int j,string &s, string &p, vector<vector<int>>&dp ){
    if (j == p.size()) return i == s.size();
    if (i == s.size()) {
            while (j < p.size() && p[j] == '*') j++;
            return dp[i][j] = (j == p.size());
        }  
    if(dp[i][j]!=-1)return dp[i][j]; 

    if(p[j]=='?'){return dp[i][j]= solve(i+1,j+1,s,p,dp);}
    else if(p[j]=='*'){return dp[i][j]= solve(i,j+1,s,p,dp) or solve(i+1,j,s,p,dp);}
    else if(s[i]==p[j]){return dp[i][j]= solve(i+1,j+1,s,p,dp);}
    return false;
}
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
       return  solve(0,0,s,p,dp);
    }
};