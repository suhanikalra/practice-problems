class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp1;
        for(auto k: s){
            mp1[k]++;

        }
        for(auto k: t){
            mp1[k]--;
            if(mp1[k]<0)return k;
            
        }
        return ' ';
        
    }
};