class Solution {
public:
    bool solve(vector<vector<char>>& board, int i, int j, string& word,
               int index) {

        if (index == word.length())
            return true;
        if (i < 0 || j < 0 || i >= board.size() or j >= board[0].size() ||
            board[i][j] != word[index])
            return false;
        if (board[i][j] == '#')
            return false;

        char temp = board[i][j];
        board[i][j] = '#';
        bool res = solve(board, i + 1, j, word,index+1) or
                   solve(board, i, j + 1, word, index+1) or
                   solve(board, i - 1, j, word, index+1) or
                   solve(board, i, j - 1, word, index+1);
        board[i][j] = temp;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
     
        bool a = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (solve(board, i, j, word, 0) == true)
                        return true;
                }
            }
        }
        return false;
    }
};
