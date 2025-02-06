class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string,vector<int>>mp;int i=0;
        for(auto k: wordsDict){
            mp[k].push_back(i++);
        }
        int mini=1000000;
        for(auto i:mp[word1]){
             for(auto j:mp[word2]){
                mini= min(mini,abs(i-j));
             }
        }
        return mini;
    }
};