class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        set<char> vowel = {'a','e','i','o','u'};
        vector<int> prefixSum(words.size() + 1, 0);
        
        for(int i = 0; i < words.size(); i++) {
            string &k = words[i];
            prefixSum[i + 1] = prefixSum[i] + 
                (vowel.count(k[0]) && vowel.count(k.back()) ? 1 : 0);
        }
        
        vector<int> res;
        for(auto &query : queries) {
            res.push_back(prefixSum[query[1] + 1] - prefixSum[query[0]]);
        }
        
        return res;
    }
};