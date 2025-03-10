class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&grid){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]=='0')return;
        grid[i][j]='0';
        int dx[]= {1,-1,0,0};
        int dy[]={0,0,-1,1};
        for(int p=0;p<4;p++){
            int newx= i+dx[p];
            int newy= j+dy[p];
            if(newx>=0 and newx<grid.size() and newy>=0 and newy<grid[0].size() and grid[newx][newy]=='1'){
                dfs(newx,newy,grid);
            }
        }


    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){dfs(i,j,grid);count++;}
            }
        }
        return count;
    }
};