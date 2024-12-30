class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end()); 
        vector<int> res;

        for (auto s : spells) {
            int start = 0, end = potions.size() - 1;

          
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if ((long long)potions[mid] * s >= success) {
                    end = mid - 1; 
                } else {
                    start = mid + 1; 
                }
            }

            res.push_back(potions.size() - start);
        }

        return res;
    }
};
