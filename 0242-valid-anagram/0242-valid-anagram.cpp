class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp1,mp2;
        for(auto k: s){mp1[k]++;}
         for(auto k: t){mp2[k]++;}
        
        return mp1==mp2;

    }
};