class Solution {
public:
    int expand(int i, int j, string &s, int &start) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        start = i + 1;          // correct start
        return j - i - 1;       // length
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxi = 0;
        int localstart = 0;

        for (int i = 0; i < n; i++) {
            int start1, start2;

            int a = expand(i, i, s, start1);       // odd
            int b = expand(i, i + 1, s, start2);   // even

            if (a > maxi) {
                maxi = a;
                localstart = start1;
            }
            if (b > maxi) {
                maxi = b;
                localstart = start2;
            }
        }
        return s.substr(localstart, maxi);
    }
};