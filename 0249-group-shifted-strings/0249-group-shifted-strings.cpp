class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string,vector<string>>mp;
        
        for (auto &s : strings) {
            string key;
            for (int i = 1; i < s.size(); i++) {
                int diff = (s[i] - s[i - 1] + 26) % 26; 
                key += to_string(diff) + ",";
            }
            mp[key].push_back(s);
        }
        vector<vector<string>>res;
        for(auto k: mp){
            res.push_back(k.second);
        }
            
        return res;
    }
};