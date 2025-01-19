class Solution {
public:
void dfs(int i,int j,vector<vector<int>>& grid,int dx[],int dy[]){
   if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()  || grid[i][j] != 1) {
        return; 
    }
        grid[i][j]=2;
        
        for(int p=0;p<4;p++){
            auto newRow=i+dx[p];
            int newCol=j+dy[p];
                  if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 1) {
dfs(i+dx[p],j+dy[p],grid,dx,dy);}
        
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int dx[]= {1,-1,0,0};
        int dy[]= {0,0,1,-1};
        for(int i=0;i<grid[0].size();i++){
            if(grid[0][i]==1)dfs(0,i,grid,dx,dy);
            if(grid[grid.size()-1][i]==1)dfs(grid.size()-1,i,grid,dx,dy);
        }
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==1)dfs(i,0,grid,dx,dy);
            if(grid[i][grid[0].size()-1]==1)dfs(i,grid[0].size()-1,grid,dx,dy);
        }
int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)count++;
            }
        }
        return count;
    }
};