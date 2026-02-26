class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int start=0;int maxi=0;
        for( int end= 0;end<s.size();end++){
            mp[s[end]]++;
            while( mp[s[end]]>1){
                mp[s[start]]--;
                if( mp[s[start]]==0)mp.erase(s[start]);
                start++;
            }
            maxi= max( maxi, end-start+1);

        }
        return maxi;
    }
};