class Solution {
public:
void dfs(int i,int j,vector<vector<char>>& board){
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') {
            return;
        }
    board[i][j] = 'Z';
    int dx[]={1,-1,0,0};
    int dy[]= {0,0,-1,1};
    for (int k = 0; k < 4; k++) {
            int newx = i + dx[k];
            int newy = j + dy[k];
            dfs(newx, newy, board);
        }
    
}
    void solve(vector<vector<char>>& board) {
         if (board.empty() || board[0].empty()) return;
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){dfs(i,0,board);}
            if(board[i][board[0].size()-1]=='O'){dfs(i,board[0].size()-1,board);}
        }

        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O'){dfs(0,i,board);}
            if(board[board.size()-1][i]=='O'){dfs(board.size()-1,i,board);}
        }

        for(int i= 0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){board[i][j]='X';}
            }
        }

        for(int i= 0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='Z'){board[i][j]='O';}
            }
        }
        
    }
};