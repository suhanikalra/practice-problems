class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        memo = [[[-1] * 2 for _ in range(2)] for _ in range(n)]
        
        def solve(idx, buy, t):
            if idx == n or t == 2: return 0
            if memo[idx][buy][t] != -1: return memo[idx][buy][t]
            
            ans = 0
            if buy:
                buy_skip = solve(idx + 1, 1, t)
                buy_take = solve(idx + 1, 0, t) - prices[idx]
                
                ans = max(buy_skip, buy_take)
                
            else:
                sell_skip = solve(idx + 1, 0, t)
                sell_take = solve(idx + 1, 1, t + 1) + prices[idx]
                
                ans = max(sell_skip, sell_take)
                
            memo[idx][buy][t] = ans
            return ans
            
        return solve(0, 1, 0)