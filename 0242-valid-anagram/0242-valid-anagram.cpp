class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!= t.size())return false;
       unordered_map<char,int>mp;
       for(auto k:s){
        mp[k]++;
       }
       for(auto k:t){
        if(mp[k]==0)return false;
        mp[k]--;
        if(mp[k]==0)mp.erase(k);
       }
       if(mp.size()==0)return true;

       return false;


    }
};