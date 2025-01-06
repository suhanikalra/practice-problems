class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        for(auto k: s){
            mp[k]++;
        }
        int i=0;
        for(auto k: s){
            
            if(mp[k]==1)return i;
            i++;
        }
        return -1;
    }
};