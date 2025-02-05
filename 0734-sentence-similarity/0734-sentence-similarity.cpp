class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
       if(sentence1.size() != sentence2.size()) return false;
        set<pair<string,string>> similarSet;
        for( auto& p : similarPairs) {
            similarSet.insert({p[0], p[1]});
            similarSet.insert({p[1], p[0]});
        }
        
        for(int i = 0; i < sentence1.size(); i++) {
            if(sentence1[i] == sentence2[i]) continue;
            
            if(similarSet.find({sentence1[i], sentence2[i]}) == similarSet.end()) {
                return false;
            }
        }
        return true;
    
    }
};