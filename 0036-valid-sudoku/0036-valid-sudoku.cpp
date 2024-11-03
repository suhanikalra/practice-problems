class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n= board.size();
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for(int i=0; i<n;i++){
            for(int j=0;j<n;j++){
                if (board[i][j] == '.') continue;
            if(rows[i].find(board[i][j])==rows[i].end()) {rows[i].insert(board[i][j]);}
            else return false;
             if(cols[j].find(board[i][j])==cols[j].end()) {cols[j].insert(board[i][j]);}
            else return false;
             int boxIndex = (i / 3) * 3 + (j / 3);
                if (boxes[boxIndex].find(board[i][j]) != boxes[boxIndex].end()) return false;
                boxes[boxIndex].insert(board[i][j]);

        }}
        return true;
    }
};