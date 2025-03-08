class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int>mp;int maxi=0;
       int start=0;int end=0;
       while(end<s.size()){
        mp[s[end]]++;
        while(mp[s[end]]>1){
            if(start<end){mp[s[start]]--; start++;}
            if(mp[s[start]]==0){mp.erase(s[start]);start++;}
        }
        maxi= max(end-start+1,maxi);
        end++;
       }
       return maxi;
    }
};