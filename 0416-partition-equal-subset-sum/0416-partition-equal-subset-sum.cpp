class Solution {
public:
    bool solve(vector<int>& nums, int sum, int n, vector<vector<int>>& memo) {
        if (sum == 0) return true;
        if (n < 0) return false;
        
        if (memo[n][sum] != -1) return memo[n][sum];
        
        if (nums[n] > sum) {
            return memo[n][sum] = solve(nums, sum, n-1, memo);
        }
        
        return memo[n][sum] = solve(nums, sum - nums[n], n-1, memo) || 
                               solve(nums, sum, n-1, memo);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int k : nums) {
            sum += k;
        }
        
        if (sum % 2 != 0) return false;
        
        vector<vector<int>> memo(nums.size(), vector<int>(sum/2 + 1, -1));
        
        return solve(nums, sum/2, nums.size()-1, memo);
    }
};