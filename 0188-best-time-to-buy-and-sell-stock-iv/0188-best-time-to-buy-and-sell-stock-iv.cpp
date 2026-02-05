class Solution {
public:
vector<vector<vector<int>>> dp;
int solve( int i,int buy, int count,int k, vector<int>& prices){
    if( i==prices.size() or count==k)return 0;
    if( dp[i][buy][count]!=-1)return  dp[i][buy][count];
    if( buy){
        return dp[i][buy][count]= max((-prices[i]+ solve( i+1,0,count,k,prices )),solve( i+1,1,count,k,prices ));}

    else return  dp[i][buy][count]= max({ (prices[i]+ solve( i+1,1,count+1,k,prices )),solve( i+1,0,count,k,prices )});

    }

    int maxProfit(int k, vector<int>& prices) {
        dp = vector<vector<vector<int>>>(prices.size(),
              vector<vector<int>>(2, vector<int>(k, -1)));
        return solve( 0,1,0,k,prices );//index,buy/sell,count

    }
};