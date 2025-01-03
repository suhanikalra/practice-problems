class Solution {
public:
    bool solve(int i, vector<int>& nums, int total, int sum, vector<vector<int>>& dp) {
        if(total == sum/2) return true;
        if(i >= nums.size()) return false;
        if(total >sum/2) return false;
        
        if(dp[i][total] != -1) return dp[i][total];
         if (nums[i] > sum/2) {
            return dp[i][total] =  solve(i+1, nums, total, sum, dp);
        }
        
         return dp[i][total] = solve(i+1, nums, total+nums[i], sum, dp) || 
                     solve(i+1, nums, total, sum, dp);
                     
       
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto k: nums) sum += k;
        if(sum % 2 == 1) return false;
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));
        
        return solve(0, nums, 0, sum, dp);
    }
};