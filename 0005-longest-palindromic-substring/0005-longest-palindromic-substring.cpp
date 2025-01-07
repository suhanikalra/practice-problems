class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        
        int start = 0;
        int maxLength = 1;
        
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                if(j - i + 1 > maxLength && isPalindrome(s, i, j)) {
                    start = i;
                    maxLength = j - i + 1;
                }
            }
        }
        
        return s.substr(start, maxLength);
    }
};