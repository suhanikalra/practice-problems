class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
          unordered_map<string,vector<int>>mp;int i=0;
        for(auto k: wordsDict){
            mp[k].push_back(i++);
        }
        int mini=1000000;
        if(word1 != word2){
        for(auto i:mp[word1]){
            //  for(auto j:mp[word2]){
            //     mini= min(mini,abs(i-j));
        auto it = lower_bound(mp[word2].begin(), mp[word2].end(), i);
                if(it != mp[word2].end()) {
                    mini = min(mini, abs(i - *it));
                }
                if(it != mp[word2].begin()) {
                    mini = min(mini, abs(i - *(--it)));
                }          }
        
        return mini;}
        else {sort(mp[word1].begin(),mp[word1].end());
        int prev=100000;
        for(auto k:mp[word1]){
            mini= min(abs(prev-k),mini);
            prev=k;
        }}
        return mini;


    }
};