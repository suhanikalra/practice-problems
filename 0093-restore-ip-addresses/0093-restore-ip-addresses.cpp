class Solution {
public:
    void solve(string s, int index, string curr, vector<string>& ans, int n, int segment) {
        // If we have used all characters and have formed 4 segments
        if (index == n && segment == 4) {
            curr.pop_back(); // Remove the last dot
            ans.push_back(curr);
            return;
        }

        // If we have 4 segments already or exceeded string length, return
        if (segment == 4 || index >= n) {
            return;
        }

        // Try to create segments of length 1, 2, and 3
        for (int len = 1; len <= 3; ++len) {
            if (index + len > n) break; // Prevent out-of-bounds access
            string segmentStr = s.substr(index, len);
            int value = stoi(segmentStr); // Convert substring to integer

            // Check if the segment is valid
            if (value <= 255 && !(segmentStr[0] == '0' && segmentStr.size() > 1)) {
                solve(s, index + len, curr + segmentStr + ".", ans, n, segment + 1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        string curr = ""; // Initialize curr as an empty string
        solve(s, 0, curr, ans, n, 0); // Start from index 0 and segment 0
        return ans;
    }
};
