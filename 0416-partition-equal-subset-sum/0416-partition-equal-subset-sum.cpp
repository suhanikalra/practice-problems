class Solution {
public:
bool solve(int i, int target,vector<int>& nums,vector<vector<int>>&dp){
    if(i>= nums.size())return false;
    if(target<0)return false;
    if(target==0)return true;
    if(dp[i][target]!= -1)return dp[i][target];
    return dp[i][target]=solve(i+1,target-nums[i],nums,dp) or solve(i+1,target,nums,dp);
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto k: nums)sum+=k;
        if(sum%2!=0)return false;
 
        vector<vector<int>>dp(nums.size(),vector<int>(sum/2+1,-1));
        
      return solve(0,sum/2,nums,dp);
    }
};