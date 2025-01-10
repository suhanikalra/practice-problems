class Solution {
public:
int solve(int i,vector<int>& nums,int ans,vector<int>&dp){
    if(i>=nums.size())return 0;
    if(dp[i]!=-1)return dp[i];
    return dp[i]=max(solve(i+2,nums,ans+nums[i],dp)+nums[i],solve(i+1,nums,ans+nums[i],dp));

}
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
vector<int>dp(nums.size()+1,-1);
        return solve(0,nums,0,dp);
        
    }
};