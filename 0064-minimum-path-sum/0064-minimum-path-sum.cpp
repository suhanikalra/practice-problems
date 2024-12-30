class Solution {
public:
int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
    if(i>=grid.size() or j>=grid[0].size())return 100000;
    if(i==grid.size()-1 and j==grid[0].size()-1)return grid[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
int a= solve(grid,i+1,j,dp)+grid[i][j];
int b= solve(grid,i,j+1,dp)+grid[i][j];
    return dp[i][j]=min(a,b);
}
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
       return solve(grid,0,0,dp);
    }
};