class Solution {
public:
int solve(string s,string k, int i,int j, int ans){
    if( i== s.size() or j==s.size())return 0;
    if( s[i]==k[j]){
        return 1+solve(s,k,i+1,j+1,ans);
    }

    else return max( solve(s,k,i+1,j,ans),solve(s,k,i,j+1,ans));
}
    int longestPalindromeSubseq(string s) {
        string k=s;
        string ans="";
        reverse(k.begin(),k.end());
        return solve(s,k,0,0,0);
    }
};