class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>pfreq;
        unordered_map<char,int>sfreq;
        vector<int>ans;int start=0,end=0;
        for(auto k: p){pfreq[k]++;}

        if(p.size()>s.size())return {};

        for( end=0;end<p.size();end++){
            sfreq[s[end]]++;

        }
        if(sfreq==pfreq)ans.push_back(start);
        for(;end<s.size();end++){
            sfreq[s[end]]++;
            sfreq[s[start]]--;
             if(sfreq[s[start]]==0)sfreq.erase(s[start]);
            start++;
           
            if(sfreq==pfreq)ans.push_back(start);
        }
        return ans;

    }
};