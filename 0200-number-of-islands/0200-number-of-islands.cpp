class Solution {
public:

    void dfs(int i, int j,vector<vector<char>>& grid){
        
        grid[i][j]='0';
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for( int ind=0;ind<4;ind++){
            int newx= i+dx[ind];
            int newy= j+dy[ind];

            if(newx>=0 and newy>=0 and newx<grid.size() and newy<grid[0].size() and grid[newx][newy]=='1'){
                dfs(newx,newy,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for( int i=0;i<grid.size();i++){
            for( int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};