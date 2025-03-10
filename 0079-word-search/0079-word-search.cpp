class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board, string& word, int index) {
        if (index == word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*' || board[i][j] != word[index]) 
            return false;
        
        char temp = board[i][j];
        board[i][j] = '*';
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        bool found = false;
        for (int p = 0; p < 4; p++) {
            int newx = i + dx[p];
            int newy = j + dy[p];

            if (dfs(newx, newy, board, word, index + 1)) {
                found = true;
                break;
            }
        }
        
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool k= false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    k=k or dfs(i,j,board,word,0);
                }
            }
        }
        return k;

        


    }
};