class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int maxsofar=prices[prices.size()-1];
        int profit=0;
        for(int i = prices.size()-2; i >= 0; i--) { 

        profit= max(profit,maxsofar-prices[i]);
        maxsofar= max(maxsofar,prices[i]);
        }
        return profit;
    }
};