class Solution {
public:
int r(vector<int>& nums,int i,vector<int> &dp){
    if(i>=nums.size()) return 0;
    if(dp[i] != -1 )return dp[i];
     int pick = r(nums, i + 2,dp) + nums[i];
    int notpick=r(nums,i+1,dp);
    return dp[i]=max(pick,notpick);
}
    int rob(vector<int>& nums) {
          vector<int> dp(nums.size(), -1);
return r(nums,0,dp);
   }
};