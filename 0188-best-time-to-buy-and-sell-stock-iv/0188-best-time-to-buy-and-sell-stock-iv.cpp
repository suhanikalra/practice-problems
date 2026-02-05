class Solution {
public:
int solve( int i,int buy, int count,int k, vector<int>& prices){
    if( i==prices.size() or count==k)return 0;
    if( buy){
        return max((-prices[i]+ solve( i+1,0,count,k,prices )),solve( i+1,1,count,k,prices ));}

    else return max({ (prices[i]+ solve( i+1,1,count++,k,prices )),solve( i+1,0,count,k,prices )});

    }

    int maxProfit(int k, vector<int>& prices) {
        return solve( 0,1,0,k,prices );//index,buy/sell,count

    }
};