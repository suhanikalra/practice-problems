class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int start=0;int end=0;unordered_map<char,int>mp;int count=0;
        while(end<s.size()){
            mp[s[end]]++;
            while(mp[s[end]]>1){
                mp[s[start]]--;
                if(mp[s[start]]==0)mp.erase(s[start]);start++;
            }
            count+=(end-start+1);
            end++;
        }
        return count;
    }
};