class Solution {
public:

    int solve(int i,int j,vector<vector<int>>& grid){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0)return 0;
      
        int current = grid[i][j];
        
    
        grid[i][j] = 0;
           int ans= solve(i-1,j,grid)+ solve(i+1,j,grid)+ solve(i,j+1,grid)+solve(i,j-1,grid)+current;
            
            return ans;
        
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;int k,maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){k=solve(i,j,grid);
                maxi=max(k,maxi);}
            }
        }
        return maxi;
    }
};