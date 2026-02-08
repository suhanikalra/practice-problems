class Solution {
public:
bool ans= false;
void dfs( int index,int i,int j,vector<vector<char>>& board, string word){
    if( index>=word.size()-1){ans= true;return;}
    if( board[i][j]==word[index]){
        auto temp=  board[i][j];
        board[i][j]='$';

        int dx[]={0,0,1,-1};
        int dy[]= {1,-1,0,0};

        for( int ind=0;ind<4;ind++){
            auto newx=i+dx[ind];
            auto newy= j+ dy[ind];
            if( newx>=0 and newx<board.size() and newy>=0 and newy<board[0].size() and board[newx][newy]==word[index+1])dfs(index+1,newx,newy, board,word);
        }
         board[i][j]=temp;

    }
}
    bool exist(vector<vector<char>>& board, string word) {
        
        for( int i=0;i<board.size();i++){
            for( int j=0;j<board[0].size();j++){
                if( board[i][j]==word[0] ){
                    dfs(0,i,j, board,word);
                }
            }
        }
        return ans;
    }
};