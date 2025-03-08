class Solution {
public:
void dfs(int i,int j,vector<vector<char>> &grid){
    if(i>=grid.size() or j>= grid[0].size() or i<0 or j<0 or grid[i][j]=='0')return;
   grid[i][j]='0';
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    for(int t=0;t<4;t++){
        dfs(i+dx[t],j+dy[t],grid);
    }

    

}
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]== '1'){dfs(i,j,grid);
                count++;}
                
            }
        }
        return count;
       
    }
};