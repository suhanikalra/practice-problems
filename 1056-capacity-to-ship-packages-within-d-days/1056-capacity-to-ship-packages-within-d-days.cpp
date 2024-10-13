class Solution {
public:
bool solve(vector<int>& weights, int days, int n){
    int sum=0; int count= 1;
    for(auto weight: weights){
        sum+=weight;
        if(sum>n){
            count++;
            sum=weight;
        }

    }
    if (count>days)return false;
    return true;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low= *max_element(weights.begin(),weights.end());
        int high = 0;
        for( auto weight : weights){
            high +=weight;
        }
        int ans= 0;
        while(low<=high){
            int mid= low+ (high-low)/2;

            if(solve(weights,days,mid)== true){
                ans= mid;
                high = mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
};