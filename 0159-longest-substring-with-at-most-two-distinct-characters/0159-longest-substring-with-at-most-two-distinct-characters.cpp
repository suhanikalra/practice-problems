class Solution {
public:

    int lengthOfLongestSubstringTwoDistinct(string s) {
int start=0;int end=0;int maxi= INT_MIN;
        unordered_map<char,int>mp;
        while(end<s.size()){
            mp[s[end]]++;
            while(mp.size()>2){
                mp[s[start]]--;
                 if (mp[s[start]] == 0) mp.erase(s[start]);start++;

            }
            maxi=max(end-start+1,maxi);end++;
        }
        
        return maxi == INT_MIN ? 0 : maxi;
    }
};