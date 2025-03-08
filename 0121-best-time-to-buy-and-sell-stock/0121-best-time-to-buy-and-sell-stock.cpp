class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;int ans=0;
        for(auto k: prices){
            mini= min(k,mini);
            ans= max(k-mini,ans);
        }
        return ans;
        
    }
};