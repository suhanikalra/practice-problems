class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        //using hash set
        unordered_map <string,int>mp;
        for(auto &path: paths){
            mp[path[0]]=1;
        }

       for (auto &path : paths) {
            if (mp[path[1]] != 1) {
                return path[1];
            }}
            return " ";
       
    }
};