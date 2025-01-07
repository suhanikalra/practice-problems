class Solution {
public:
    string result = "";
    
    int solve(string &s, string &p, int i, int j, string ans) {
        if (result.size() < ans.size()) 
            result = ans;

        if (i == s.size() || j == p.size())
            return result.size();

        if (s[i] == p[j]) {
            solve(s, p, i + 1, j + 1, ans + s[i]);
        }
        else{solve(s, p, i + 1, j, "");
        solve(s, p, i, j + 1, "");}

        return result.size();
    }

    string longestPalindrome(string s) {
        string p = s;
        reverse(p.begin(), p.end());
        string ans = "";
        solve(s, p, 0, 0, ans);
        return result;
    }
};
