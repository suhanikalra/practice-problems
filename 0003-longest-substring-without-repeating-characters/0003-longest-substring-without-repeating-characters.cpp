class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0;int end=0;
        int maxi=INT_MIN;
        unordered_map<int,int>mp;
        while(end<s.size()){
            while(mp.find(s[end])!=mp.end()){
                mp[s[start]]--;
                if(mp[s[start]]==0){mp.erase(s[start]);}
                start++;
            }
            maxi= max(maxi,end-start+1);

            mp[s[end]]++;
            end++;
        }
        if(maxi==INT_MIN)return 0;
return maxi;
        
    }
};