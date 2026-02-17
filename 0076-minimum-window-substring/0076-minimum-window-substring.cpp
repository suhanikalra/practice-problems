class Solution {
public:
    string minWindow(string s, string t) {
        if( t.size()>s.size())return "";
        unordered_map<char, int> mp;
        for (auto c : t) mp[c]++;
        int count= t.size();
        int minLen = INT_MAX, minStart = 0;
        int start=0,end= 0; 
        while( end< s.size()){
            if (mp.find(s[end]) != mp.end()) {
            mp[s[end]]--;
            if( mp[s[end]]==0)count--;
        }
        while (count == 0) {
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }

                if (mp.find(s[start]) != mp.end()) {
                    mp[s[start]]++;
                    if (mp[s[start]] > 0)
                        count++;
                }

                start++;
            }

            end++;
        }

        if (minLen == INT_MAX) return "";
        return s.substr(minStart, minLen);

    }
};