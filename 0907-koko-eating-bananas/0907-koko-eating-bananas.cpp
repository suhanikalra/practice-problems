class Solution {
public:
bool solve(int k,vector<int>& piles, int h){
    long long count=0;
      for(auto p: piles){
        count += ((p%k==0)?p/k:p/k+1);  
    }
   
    return count<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int start= 1;
        int ans=0;
        int end=*max_element(piles.begin(),piles.end());
        while(start<=end){
            int mid= (end-start)/2+start;
            if(solve(mid,piles,h)){ans=mid;
            end= mid-1;}
            else{start= mid+1;}
        }
        return ans;
    }
};