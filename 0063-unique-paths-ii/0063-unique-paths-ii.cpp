class Solution {
public:
int solve(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>>&dp){
       
    if(i>=obstacleGrid.size() or j==obstacleGrid[0].size()  )return 0;
     if(obstacleGrid[i][j]==1)return 0;
        if(i==obstacleGrid.size()-1 and j==obstacleGrid[0].size()-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
       return dp[i][j]=solve(obstacleGrid,i+1,j,dp)+ solve(obstacleGrid,i,1+j,dp);


}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return solve(obstacleGrid,0,0,dp);
    }
};