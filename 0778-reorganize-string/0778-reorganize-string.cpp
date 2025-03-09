class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        
                for (char k : s) {
            mp[k]++;
            if (mp[k] > (n + 1) / 2) return "";  
        }
        
        string ans = "";
        
        priority_queue<pair<int, char>> pq;
        for (auto& [ch, freq] : mp) {
            pq.push({freq, ch});
        }
        
        while (!pq.empty()) {
            auto fi = pq.top(); pq.pop();
            
            if (pq.empty()) { 
                ans += fi.second; 
                break;
            }
            
            auto sec = pq.top(); pq.pop();
            
            ans += fi.second;
            ans += sec.second;
            
            if (fi.first - 1 > 0) pq.push({fi.first - 1, fi.second});
            if (sec.first - 1 > 0) pq.push({sec.first - 1, sec.second});
        }
        
        return ans;
    }
};
