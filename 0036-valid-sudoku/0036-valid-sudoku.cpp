class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                else {
                    auto x = board[i][j];
                    for (int k = 0; k < 9; k++) {

                        if (k != j && board[i][k] == x)
                            return false;
                        if (k != i && board[k][j] == x)
                            return false;

                        int boxRow = (i / 3) * 3;
                        int boxCol = (j / 3) * 3;

                        for (int r = boxRow; r < boxRow + 3; r++) {
                            for (int c = boxCol; c < boxCol + 3; c++) {
                                if (r == i && c == j)
                                    continue;
                                if (board[r][c] == x)
                                    return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};