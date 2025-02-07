class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mp; 
        unordered_map<int, int> freq; 
        vector<int> ans;

        for (auto &q : queries) {
            int key = q[0], value = q[1];

            if (mp.count(key)) {
                int old_value = mp[key];
                freq[old_value]--;
                if (freq[old_value] == 0) freq.erase(old_value);
            }

            mp[key] = value;
            freq[value]++;

            ans.push_back(freq.size());
        }
        return ans;
    }
};
