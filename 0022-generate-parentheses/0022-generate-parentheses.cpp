class Solution {
public:
void solve(int open,int close,string ans,vector<string>&result,int n){
    if(open==n and close==n){result.push_back(ans);return; }
    if(open<n)solve(open+1,close,ans+"(",result,n);
    if(close<open)solve(open,close+1,ans+")",result,n);
}
    vector<string> generateParenthesis(int n) {
        string ans= "(";
        vector<string> result;
        solve(1,0,ans,result,n);
        return result;
        
    }
};