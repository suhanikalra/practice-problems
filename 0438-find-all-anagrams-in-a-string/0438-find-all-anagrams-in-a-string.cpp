class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int end=0;
        int start=0;
        if(p.length()>s.length())return {};
        vector<int> pfreq(26, 0);
        vector<int> windowFreq(26, 0);
        for(auto c:p){pfreq[c-'a']++;}
        for(end;end<p.size();end++){
           windowFreq[s[end] - 'a']++;
        }
        if(windowFreq==pfreq){ans.push_back(start);}
        for(end;end<s.size();end++){
            windowFreq[s[end] - 'a']++;
             windowFreq[s[start] - 'a']--;
           
            start++;
            if(windowFreq==pfreq){ans.push_back(start);}
        }
        return ans;

    }
};