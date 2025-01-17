class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;int count=0;
        int start=0,end=0;
        while(end<s.size()){
            mp[s[end]]++;
            while(mp[s[end]]>1){
                mp[s[start]]--;
                if(mp[s[start]]==0)mp.erase(mp[s[start]]);
                start++;

            }
            count=max(count,end-start+1);
            end++;
        }
        return count;
    }
};