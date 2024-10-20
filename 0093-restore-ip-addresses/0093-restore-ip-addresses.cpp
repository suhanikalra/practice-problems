class Solution {
public:
    void solve(string s, int index, string curr, vector<string>& ans, int n, int segment) {
        if (index == n && segment == 4) {
            curr.pop_back(); 
            ans.push_back(curr);
            return;
        }

        if (segment == 4 || index >= n) {
            return;
        }

        for (int len = 1; len <= 3; ++len) {
            if (index + len > n) break; 
            string segmentStr = s.substr(index, len);
            int value = stoi(segmentStr); 

            if (value <= 255 && !(segmentStr[0] == '0' && segmentStr.size() > 1)) {
                solve(s, index + len, curr + segmentStr + ".", ans, n, segment + 1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        string curr = ""; 
        solve(s, 0, curr, ans, n, 0); 
        return ans;
    }
};
