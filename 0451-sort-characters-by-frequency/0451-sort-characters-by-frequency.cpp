class Solution {
public:
    static bool cmp(pair<char,int>& a, pair<char,int>& b) {
        if(a.second != b.second) 
            return a.second > b.second;
        return a.first < b.first;
    }
    
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for(char c : s) {
            freqMap[c]++;
        }
        
        vector<pair<char, int>> freq;
        for(auto& pair : freqMap) {
            freq.push_back(pair);
        }
        
        sort(freq.begin(), freq.end(), cmp);
        
        string result = "";
        for(auto& p : freq) {
            result += string(p.second, p.first);
        }
        
        return result;
    }
};