class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0,maxi=INT_MIN;
        for(auto k: nums){
            currsum= max(k+currsum,k);
            maxi=max(maxi,currsum);
        }
        return maxi;
        
    }
};