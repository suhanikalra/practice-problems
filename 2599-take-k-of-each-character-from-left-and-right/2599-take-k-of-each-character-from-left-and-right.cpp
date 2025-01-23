class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char,int>mp;
         unordered_map<char,int>mp2;
        for(auto p: s){
            mp[p]++;
        }
        if (mp['a'] < k || mp['b'] < k || mp['c'] < k) {
            return -1; 
        }
        int count=0;int maxi=0;
        int start=0,end=0;
        for (int end = 0; end < s.size(); end++) {
            mp2[s[end]]++;

            while (mp2['a'] > mp['a'] - k || mp2['b'] > mp['b'] - k || mp2['c'] > mp['c'] - k) {
                mp2[s[start]]--;
                start++;
            }

            maxi = max(maxi, end - start + 1);
        }

        return s.size()-maxi;
    }
};