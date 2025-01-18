class Solution {
public:
void dfs(vector<vector<int>>& grid,int i,int j){
    if(grid[i][j]==0){
    grid[i][j]=2;}
    int dx[]={1,-1,0,0};
    int dy[]={0,0,-1,1};
    for(int p=0;p<4;p++){
        if(i+dx[p]>=0 and i+dx[p]<grid.size() and j+dy[p]>=0 and j+dy[p]<grid[0].size() and grid[i+dx[p]][j+dy[p]]==0)
        dfs(grid,i+dx[p],j+dy[p]);
    }
}
    int closedIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][0] == 0) dfs(grid, i, 0); 
            if (grid[i][grid[0].size() - 1] == 0) dfs(grid, i, grid[0].size() - 1); 
        }

        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[0][j] == 0) dfs(grid, 0, j); 
            if (grid[grid.size() - 1][j] == 0) dfs(grid, grid.size() - 1, j); 
        }
int count=0;
        for(auto i=1;i<grid.size()-1;i++){
            for(int j=1;j<grid[0].size()-1;j++){
                if(grid[i][j]==0){dfs(grid,i,j);count++;}
            }
        }
        return count;
        
    }
};