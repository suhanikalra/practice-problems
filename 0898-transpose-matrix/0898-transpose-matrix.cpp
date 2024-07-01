class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();    // Number of rows in original matrix
        int n = matrix[0].size(); // Number of columns in original matrix

        vector<vector<int>> result(n, vector<int>(m)); // Initialize result with dimensions n x m

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][i] = matrix[i][j]; // Transpose matrix elements
            }
        }

        return result;
    }
};
