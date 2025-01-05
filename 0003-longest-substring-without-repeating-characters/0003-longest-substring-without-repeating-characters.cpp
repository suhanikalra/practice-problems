class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0;int end=0;
        unordered_map<int,int>mp;
        int maxi=0;

        while(end<s.size()){
            mp[s[end]]++;
            while(mp[s[end]]>1){
                mp[s[start]]--;
                if(mp[s[start]]==0){mp.erase(s[start]);}
                start++;
            }
            maxi= max(maxi,end-start+1);
            end++;

        }
        return maxi;
    }
};