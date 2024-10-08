class Solution {
public:

int lps(string &s,string &t,vector<vector<int>> &dp,int i, int j){
        if (i==s.size( ) || j==t.size()) return 0;
if(dp[i][j] != -1)return dp[i][j];
        if (s[i]== t[j]){ return dp[i][j]= lps(s,t,dp,i+1,j+1)+1;}
        else { return dp[i][j]=max(lps(s,t,dp,i,j+1),lps(s,t,dp,i+1,j)); }
    }
    int minInsertions(string s) {
        int n= s.size();
        vector<vector<int>> dp(n,vector <int> (n,-1));
        string t=s;
        reverse(t.begin(),t.end());
        return t.size()-lps( s, t,dp,0,0);

    }
};