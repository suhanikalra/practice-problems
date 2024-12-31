class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp1;
        for(auto c: magazine){
            mp1[c]++;
        }
        for(auto c: ransomNote){
            mp1[c]--;
            if(mp1[c]<0)return false;
        }
        return true;
    }
};