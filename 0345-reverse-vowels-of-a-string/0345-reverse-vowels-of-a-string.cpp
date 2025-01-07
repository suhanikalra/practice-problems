class Solution {
public:
    string reverseVowels(string s) {
        set<char> sets = {'a', 'e', 'i', 'o', 'u','A','E','I','O','U'};
        int start = 0, end = s.size() - 1;
        while (start <= end) {
            if (sets.find(s[start]) != sets.end() &&
                sets.find(s[end]) != sets.end())
                {swap(s[start], s[end]);start++;end--;}
        
        else if (sets.find(s[start]) == sets.end())
            start++;
        else if (sets.find(s[end]) == sets.end())
            end--;
            else{start++;end--;}}

        return s;
    }
};