class Solution {
public:
vector<vector<string>> ans;
 void helper(string &s, vector<string> &temp, int index) {
  
        if (index == s.size()) {
            ans.push_back(temp);
            return;
        }

        string pal_string;
        
        for (int i = index; i < s.size(); i++) {
            pal_string = s.substr(index, i - index + 1);  
            if (isPalindrome(pal_string)) {  
                temp.push_back(pal_string);  
                helper(s, temp, i + 1); 
                temp.pop_back();  
            }
        }
    }

    
    bool isPalindrome(string &s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }


    vector<vector<string>> partition(string s) {
        vector<string> temp;
        helper(s,temp,0);
        return ans;
    }
};