class Solution {
public:
   int coinChangeHelper(int amount, vector<int>& coins, int index, vector<vector<int>>& memo) {
    // Base cases
    if (amount == 0) return 1;  // Found a valid combination
    if (amount < 0 || index >= coins.size()) return 0;  // No valid combination
    
    // If the subproblem has already been solved, return the stored result
    if (memo[index][amount] != -1) return memo[index][amount];
    
    // Include the coin at index `index`
    int include = coinChangeHelper(amount - coins[index], coins, index, memo);
    
    // Exclude the coin at index `index`
    int exclude = coinChangeHelper(amount, coins, index + 1, memo);
    
    // Store the result in the memoization table and return it
    memo[index][amount] = include + exclude;
    
    return memo[index][amount];
}

int change(int amount, vector<int>& coins) {
    vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
    return coinChangeHelper(amount, coins, 0, memo);
}
};