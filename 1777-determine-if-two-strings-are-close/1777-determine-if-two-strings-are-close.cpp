class Solution {
public:
    bool closeStrings(string word1, string word2) { 
        if(word1.size() != word2.size()) 
            return false;

        map<char, int> m1, m2;

        for(char c : word1) 
            m1[c]++;
        for(char c : word2) 
            m2[c]++;

        for(auto &p : m1) {
            if(m2.find(p.first) == m2.end())
                return false;
        }
        for(auto &p : m2) {
            if(m1.find(p.first) == m1.end())
                return false;
        }

        unordered_multiset<int> set1, set2;

        for(auto &p : m1) 
            set1.insert(p.second);
        for(auto &p : m2) 
            set2.insert(p.second);

        return set1 == set2;
    }
};
