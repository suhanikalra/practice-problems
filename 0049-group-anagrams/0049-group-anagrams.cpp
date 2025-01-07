class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(auto s:strs){
            string k= s;
            sort(k.begin(),k.end());
            mp[k].push_back(s);

        }
        vector<vector<string>> ans;
        for(auto p: mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};