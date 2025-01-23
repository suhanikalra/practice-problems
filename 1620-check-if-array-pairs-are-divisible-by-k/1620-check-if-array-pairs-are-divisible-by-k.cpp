class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for (int num : arr) {
            int rem = ((num % k) + k) % k; 
            mp[rem]++;
        }
        for (auto& [rem, freq] : mp) {
            if (rem == 0) { 
                if (freq % 2 != 0) return false;
            } else {
                int complement = k - rem;
                if (mp[rem] != mp[complement]) return false; 
            }
        }

        return true;
    }
};
