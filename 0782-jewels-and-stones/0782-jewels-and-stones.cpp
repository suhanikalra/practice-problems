class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>mp;
        for(auto k:jewels){
            mp[k]=0;
        }
int count=0;
        for(auto s:stones){
            if(mp.find(s)!=mp.end())count++;
        }
        return count;
    }
};