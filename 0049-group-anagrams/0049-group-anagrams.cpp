class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto str : strs){
            auto k= str;
          sort(k.begin(),k.end());
            mp[k].push_back(str);


        }

      vector<vector<string>>ans;
        for(auto val: mp){
            ans.push_back(val.second);

            

    }
    return ans;}

};