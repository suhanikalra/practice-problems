class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

    int profit= 0;
    int mini= INT_MAX;
    for(auto k: prices){
        mini= min(k,mini);
        profit= max(k-mini, profit);
    }
    return profit;
    }
};