class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>>mp;
        for(int i=0;i<s.size();i++){
        if (mp.find(s[i]) != mp.end()) {
                mp[s[i]].second=i;
            }
            else mp[s[i]]={i,i};
          
        }
        vector<pair<int,int>>p;
        for(auto k: mp ){
            p.push_back(k.second);
        }
        sort(p.begin(),p.end());

        vector<int> result;
    int prev_start = p[0].first;
    int prev_end = p[0].second;

    for (auto a : p) {
        if (a.first > prev_end) { // Start a new partition
            result.push_back(prev_end - prev_start + 1);
            prev_start = a.first;
            prev_end = a.second;
        } else { // Merge intervals
            prev_end = max(prev_end, a.second);
        }
    }

    // Add the last partition
    result.push_back(prev_end - prev_start + 1);

    return result;
        }
    
};