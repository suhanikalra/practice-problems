class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        unordered_map<int, set<int>> mp;
        vector<int> res;
        
        for(int i = 0; i < colors.size(); i++) {
            mp[colors[i]].insert(i);
        }
        
        for(auto query : queries) {
            int ind = query[0];
            int col = query[1];
            
            if(mp.find(col) == mp.end()) {
                res.push_back(-1);
                continue;
            }
            
            auto it = mp[col].lower_bound(ind);
            int ans = INT_MAX;
            
            if(it != mp[col].end()) {
                ans = *it - ind;
            }
            
            if(it != mp[col].begin()) {
                --it;
                ans = min(ans, ind - *it);
            }
            
            res.push_back(ans);
        }
        return res;
    }
};