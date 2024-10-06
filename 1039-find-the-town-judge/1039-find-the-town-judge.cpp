class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
         vector<int> trustCounts(n + 1, 0);

         for (const auto& t : trust) {
            int a = t[0], b = t[1];
            trustCounts[a]--;  
            trustCounts[b]++; 
        }

       for (int i = 1; i <= n; ++i) {
           if (trustCounts[i] == n - 1) {
                return i;
            }

        }
        return -1;
    }
};