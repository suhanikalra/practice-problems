class Solution {
public:
bool solve( int i, int sum,int curr,vector<int>& nums,vector<vector<int>>&dp){
    if( i>=nums.size())return sum==curr;
    if(curr>sum)return false;
    if( curr==sum)return true;
    return  solve( i+1,sum,curr+nums[i],nums,dp) or solve( i+1,sum,curr,nums,dp) ;
    
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
            
        }
        if( sum%2==1)return false;
        vector<vector<int>>dp(nums.size(),vector<int>(sum/2+1,-1));

        return solve( 0,sum,0,nums,dp);
    }
};