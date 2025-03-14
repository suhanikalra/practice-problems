class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto k: strs){
            string a= k;
            sort(a.begin(),a.end());
            mp[a].push_back(k);
        }
        vector<vector<string>>ans;
        for(auto &[x,y]: mp){
            ans.push_back(y);
        }
        return ans;
        
    }
};