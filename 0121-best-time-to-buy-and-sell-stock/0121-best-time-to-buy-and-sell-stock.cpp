class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int maxProfit = 0;
        int maxPrice = prices[n - 1];
        
        for (int i = n - 2; i >= 0; --i) {
            maxProfit = max(maxProfit, maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }
        
        return maxProfit;
    }
};
