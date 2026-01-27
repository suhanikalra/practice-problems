class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        unordered_map<char,int>mp;
        int start=0,end=0;int maxi=0;

        while( end<s.size()){
            mp[s[end]]++;

            while( mp[s[end]]>1){
                mp[s[start]]--;
                if( mp[s[start]]==0)mp.erase(s[start]);
                start++;
            }
            maxi=max( maxi,end-start+1);end++;
        }
        return maxi;
        
    }
};