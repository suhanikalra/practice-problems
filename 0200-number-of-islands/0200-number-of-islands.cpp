class Solution {
public:
    void dfs(int i, int j,vector<vector<char>>& grid ){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        return;
        if(grid[i][j]!='1')return;
        if(grid[i][j]=='1') {grid[i][j]='0';}
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        for(auto p=0;p<4;p++){
            dfs(i+dx[p],j+dy[p],grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
               if(grid[i][j]=='1'){ dfs(i,j,grid);count++;}
            }
        }
        return count;
        
    }
};