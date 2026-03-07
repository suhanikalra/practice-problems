class Solution {
public:
vector<string>res;
void solve( int start, int close, int n, string ans){
    if( start==n and close==n){res.push_back(ans);return;}
    if( start<n){
        solve( start+1,close, n, ans+"(");
    }
    if( close<start){
        solve( start,1+close, n, ans+")");
    }

}
    vector<string> generateParenthesis(int n) {
        string ans= "(";
        solve( 1,0, n, ans);
        return res;
    }
};