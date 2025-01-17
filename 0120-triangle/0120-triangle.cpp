class Solution {
public:

    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp ){
        if(i>=triangle.size() or j>= triangle[triangle.size()-1].size())return 1000000;
if (i == triangle.size() - 1)return triangle[i][j];
if(dp[i][j]!= -1)return dp[i][j];
        int a=solve(i+1,j,triangle,dp)+triangle[i][j];
        int b=solve(i+1,j+1,triangle,dp)+triangle[i][j];
        return dp[i][j]= min(a,b);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
      return  solve(0,0,triangle,dp);
    }
};