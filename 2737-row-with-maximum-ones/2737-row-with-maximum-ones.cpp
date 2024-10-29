class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int maxOnes = 0;
        int rowWithMaxOnes = 0;
        vector<int> onesCount(m, 0); 

        for (int k = 0; k < m * n; k++) {
            int row = k / n;
            int col = k % n;

            if (mat[row][col] == 1) {
                onesCount[row]++;
            }
        }

        for (int i = 0; i < m; i++) {
            if (onesCount[i] > maxOnes) {
                maxOnes = onesCount[i];
                rowWithMaxOnes = i;
            }
        }

        return {rowWithMaxOnes, maxOnes}; 
    }
};
