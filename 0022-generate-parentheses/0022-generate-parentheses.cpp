class Solution {
public:
    void solve(int open,int close,string ans,vector<string>&res,int n){
        if(open==n && close==open ){res.push_back(ans); return;}
        if( open< n){
            solve(open+1,close,ans+'(',res,n);

        }
        if( close<open){
            solve(open,1+close,ans+')',res,n);
        }

    }
    vector<string> generateParenthesis(int n) {
        string ans="(";
        vector<string>res;
        solve( 1,0,ans,res,n);
        return res;
    }
};