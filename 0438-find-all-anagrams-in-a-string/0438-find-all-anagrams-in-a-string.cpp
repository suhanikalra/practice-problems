class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char,char>mp_p,mp_s;int count=0;
        for(auto k: p){
            mp_p[k]++;
        }
        int start=0;int end=0;
        for(;end<p.size();end++)
            mp_s[s[end]]++;

        
        if(mp_s==mp_p)ans.push_back(0);
        for(;end<s.size();end++){
            mp_s[s[end]]++;
            mp_s[s[end-p.size()]]--;
            if( mp_s[s[end-p.size()]]==0) mp_s.erase(s[end-p.size()]);
            if(mp_s==mp_p)ans.push_back(end-p.size()+1);


        }
        return ans;
        
    }
};