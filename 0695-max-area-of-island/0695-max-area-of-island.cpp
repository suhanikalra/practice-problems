class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) {
            return 0;
        }
        
        // Mark as visited by changing 1 to 2
        grid[i][j] = 2;
        
        // Count current cell (1) plus all adjacent land cells
        return 1 + solve(grid, i+1, j) + 
                   solve(grid, i-1, j) + 
                   solve(grid, i, j+1) + 
                   solve(grid, i, j-1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        for(int i=0;i< grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int count=0;
                if(grid[i][j]==1)
                 maxArea = max(maxArea, solve(grid, i, j));
                
            }
        }
        
        return maxArea;
    }
};