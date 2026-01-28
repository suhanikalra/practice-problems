class Solution {
public:
    int n, m;

    bool check(int i, int j, int k, vector<vector<char>>& board, string& word) {
        if (k == word.size()) return true;

        if (i < 0 || j < 0 || i >= n || j >= m ||
            board[i][j] != word[k])
            return false;

        char temp = board[i][j];
        board[i][j] = '#'; 
        bool found =
            check(i+1, j, k+1, board, word) ||
            check(i-1, j, k+1, board, word) ||
            check(i, j+1, k+1, board, word) ||
            check(i, j-1, k+1, board, word);

        board[i][j] = temp; 
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] &&
                    check(i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }
};