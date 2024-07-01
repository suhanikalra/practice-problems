class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(char ch: s){
            mp[ch]++;
        }
        unordered_map<char,int>mp2;

        for(char ch: t){
            mp2[ch]++;
        }

        if (mp==mp2) return true;

        return false;
        
    }
};