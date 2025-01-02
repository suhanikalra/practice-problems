class Solution {
public:
void solve(int i,string s,string op,vector<string>&result){
    if(i==s.length()){result.push_back(op);return;}
    if(isalpha(s[i])){solve(i+1,s,op+(char)toupper(s[i]),result);
    solve(i+1,s,op+(char)tolower(s[i]),result);}
    else solve(i+1,s,op+s[i],result);

}
    vector<string> letterCasePermutation(string s) {
        string op="";
        vector<string>result;
        solve(0,s,op,result);
        return result;
    }
};