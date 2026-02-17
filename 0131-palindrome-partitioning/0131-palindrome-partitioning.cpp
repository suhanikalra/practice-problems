class Solution {
public:
bool isPal(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    vector<vector<string>>ans;
    void solve( int i, string s, vector<string>temp){
        if( i== s.size()){
            ans.push_back(temp);return;
        }
        for( int ind= i;ind<s.size();ind++){
            string first = s.substr(i, ind - i + 1);
            if( isPal(first)){
                temp.push_back(first);
                solve(ind+1,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        solve( 0, s, temp);
        return ans;
    }
};