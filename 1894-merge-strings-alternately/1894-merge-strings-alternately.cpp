class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        ans.reserve(word1.size() + word2.size()); //prealocate memory
        
        int i = 0;
        while(i < word1.size() && i < word2.size()) {
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
            i++;
        }
        
        while(i < word1.size()) {
            ans.push_back(word1[i++]);
        }
        
        while(i < word2.size()) {
            ans.push_back(word2[i++]);
        }
        
        return ans;
    }
};