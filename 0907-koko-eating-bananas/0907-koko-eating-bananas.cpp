class Solution {
public:
    bool solve(int n,vector<int>& piles, int h ){
        long long count=0 ;
        for(auto pile: piles){
            count+= ceil(pile/(n*1.0));
        }
        if (count>h )return false;
        return true;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high= *max_element(piles.begin(),piles.end());
       
int ans=0;
        while(low<= high){
            int mid = low + (high- low)/2;

            if(solve(mid,piles,h)==true){
                high= mid-1;
                ans= mid;
            }

            else
            low= mid+1;
        } 

        return ans;
    }
};