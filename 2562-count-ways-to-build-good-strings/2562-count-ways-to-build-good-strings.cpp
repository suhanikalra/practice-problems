class Solution {
public:
    int solve(int low, int high, int zero, int one, int currLen, vector<int>& dp) {
        if (currLen > high) return 0;
        if (dp[currLen] != -1) return dp[currLen];
        int count = (currLen >= low && currLen <= high) ? 1 : 0;

        count += solve(low, high, zero, one, currLen + zero, dp);
        count += solve(low, high, zero, one, currLen + one, dp);

        return dp[currLen] = count % 1000000007;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);

        
        return solve(low, high, zero, one, 0, dp);
    }
};
