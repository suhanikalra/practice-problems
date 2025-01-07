
class Solution {
public:
    bool palindRE(const string& s, int start, int end) {
     
        while (start < end && !isalnum(s[start])) {
            start++;
        }
       
        while (start < end && !isalnum(s[end])) {
            end--;
        }
        
        if (start >= end) {
            return true;
        }
        
        if (tolower(s[start]) != tolower(s[end])) {
            return false;
        }
        
        return palindRE(s, start + 1, end - 1);
    }

    bool isPalindrome(string s) {
        return palindRE(s, 0, s.size() - 1);
    }
};
