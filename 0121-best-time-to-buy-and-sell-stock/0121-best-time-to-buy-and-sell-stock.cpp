class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=100000;int ans=0;
        for( auto k: prices){
            ans= max( k-mini,ans);
            mini=min( mini,k);

        }
        return ans;
        
    }
};