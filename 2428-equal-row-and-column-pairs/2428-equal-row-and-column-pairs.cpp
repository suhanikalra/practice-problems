
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> rowMap;
        int n = grid.size();
        int pairs = 0;

        for (int i = 0; i < n; ++i) {
            string rowHash;
            for (int j = 0; j < n; ++j) {
                rowHash += "#" + to_string(grid[i][j]);
            }
            rowMap[rowHash]++;
        }

        for (int j = 0; j < n; ++j) {
            string colHash;
            for (int i = 0; i < n; ++i) {
                colHash += "#" + to_string(grid[i][j]);
            }
            pairs += rowMap[colHash];
        }

        return pairs;
    }
};