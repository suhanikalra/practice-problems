class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost = 0;
        int n = colors.size();
        
        for (int i = 0; i < n - 1; ++i) {
            if (colors[i] == colors[i + 1]) {
                totalCost += min(neededTime[i], neededTime[i + 1]);
                neededTime[i + 1] = max(neededTime[i], neededTime[i + 1]);
            }
        }
        
        return totalCost;
    }
};
