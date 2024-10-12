class Solution {
public:
    bool solve(vector<int>& nums, int i, int targetsum, vector<vector<int>>& dp) {
        if (targetsum == 0) return true;  // If we find a subset that sums to target, return true
        if (i >= nums.size() || targetsum < 0) return false;  // If out of bounds or targetsum negative, return false

        if (dp[i][targetsum] != -1) return dp[i][targetsum];  // Check memoized result

        // Either include the current number in the subset or exclude it
        dp[i][targetsum] = solve(nums, i + 1, targetsum - nums[i], dp) || solve(nums, i + 1, targetsum, dp);
        
        return dp[i][targetsum];
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);  // Calculate total sum

        if (totalSum % 2 != 0) return false;  // If total sum is odd, it's impossible to partition into equal subsets
        
        int targetsum = totalSum / 2;
        
        vector<vector<int>> dp(nums.size(), vector<int>(targetsum + 1, -1));  // Memoization table

        // Try to find if there's a subset that sums up to `targetsum`
        return solve(nums, 0, targetsum, dp);
    }
};
