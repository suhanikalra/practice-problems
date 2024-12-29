class Solution {
public:
bool solve(int capacity,vector<int>& weights, int days){
    int currentDay = 1;  
    int currentLoad = 0;
    
    for(auto w : weights){
        if(w > capacity) return false;  
        
        if(currentLoad + w > capacity){
            currentDay++;  
            currentLoad = w; 
        } else {
            currentLoad += w;
        }
    }
    
    return currentDay <= days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int start=0;int end = accumulate(weights.begin(), weights.end(), 0);
int ans=0;
        while(start<=end){
            int mid= (end-start)/2+start;
            if(solve(mid,weights,days)){ans=mid;end= mid-1;}
            else{start= mid+1;}

        }
        return ans;
    }
};