class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto k: strs){
            string p= k;
            sort(p.begin(),p.end());
            mp[p].push_back(k);

        }
        vector<vector<string>> ans;
        for(auto &[x,y]: mp){
            ans.push_back(y);
        }
        return ans;
        
    }
};