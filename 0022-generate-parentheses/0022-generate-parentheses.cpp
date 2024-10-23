class Solution {
public:
void solve(int open, int close,string ans,vector<string>&result){
if(open==0 && close==0){
    result.push_back(ans);
    return;
}
if(open>0){
    ans.push_back('(');
    solve(open-1,close,ans,result);
    ans.pop_back();
}
if(open<close and close>0){
    ans.push_back(')');
    solve(open,close-1,ans,result);
    ans.pop_back();
}
}


    vector<string> generateParenthesis(int n) {
        int open = n-1;
        int close = n;
        string ans="(";
        vector<string> result;
        solve(open,close,ans,result);
        return result;
    }
};