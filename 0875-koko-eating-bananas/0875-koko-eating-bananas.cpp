class Solution {
public:
bool solve(int mid,vector<int>& piles, int h){
    int hour=0;
for( int i=0;i<piles.size();i++){
    if( piles[i]<mid)hour++;
    else {
        hour= hour+piles[i]/mid;
        if( piles[i]%mid!=0)hour=hour+1;

    }
    
}
return hour<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
       
        int low=1; int high = *max_element(piles.begin(), piles.end());int ans=-1;
        int mid= ( high-low)/2+low;
        while( low<high){
            mid= ( high-low)/2+low;
            if (solve(mid, piles, h)){high= mid;}
            else{
                low=mid+1;
            }
        }
        return low;
    }
    
};