class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        char maxChar = ' ';  // Initialize maxChar to the smallest possible digit

        for (int i = 1; i < n - 1; i++) {
            if (num[i] == num[i-1] && num[i-1] == num[i+1]) {
                maxChar = max(maxChar, num[i]);
            }
        }

        if (maxChar == ' ') {
            return "";  // If no good integer found, return empty string
        }

        return string(3, maxChar);  // Return the largest good integer of length 3
    }
};
