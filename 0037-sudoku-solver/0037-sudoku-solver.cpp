class Solution {
public:
    bool isValid ( vector<vector<char>>& board, int i, int j, char ch) {
        
        
        for( int k=0;k<9;k++)
        {
            if(board[i][k]==ch || board[k][j]==ch)return false;
            
        }
        
        int first_i = i - i%3;
        int first_j = j - j%3;
        
        for( int r = first_i ;r<first_i+3;r++)
        {
            for( int c = first_j ;c<first_j+3;c++)
            {
                if(board[r][c]==ch)return false;
            }
        }
        
        return true;
        
    }
    bool solve(vector<vector<char>>& board) {
          for( int i=0;i<board.size();i++)
        {
            for( int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                    {
                        for( char ch = '1';ch<='9';ch++)
                        {
                            if(isValid(board, i,j, ch))
                            {
                                board[i][j]=ch;
                                
                                if( solve(board))
                                {
                                    return true;
                                }
                                
                                board[i][j]='.';
                                
                            }
                        }
                        
                        return false;
                        
                    }

                }
        }
        
        
        return true;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        
            solve( board);
    }
};