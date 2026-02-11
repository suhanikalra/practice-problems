class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> freq;
        for (char c : p) freq[c]++;

        vector<int> ans;
        int start = 0;
        int k = p.size();

        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] > 0)k--;
            freq[s[i]]--;

            while (i - start + 1 > p.size()) {
                freq[s[start]]++;
                if (freq[s[start]] > 0) k++;
                start++;
            }

            if (k == 0) ans.push_back(start);
        }
        return ans;
    }
};
