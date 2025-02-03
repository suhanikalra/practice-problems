class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int prev=INT_MIN,maxi=1;int count=0;
        for(auto k: nums){
            if(k>prev)count++;
            else if(k<=prev) count=1;
            maxi=max(maxi,count);
            prev=k;
        }
        prev= INT_MAX;count=0;
        for(auto k: nums){
            if(k<prev)count++;
            else if(k>=prev)  count=1;
            maxi=max(maxi,count);
            prev=k;
        }
        return maxi;
        
    }
};