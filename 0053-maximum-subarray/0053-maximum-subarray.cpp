class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start=0,maxi= INT_MIN,currentsum=0;
        
        for(int end=0;end<nums.size();end++ ){
            currentsum=max(nums[end],currentsum+nums[end]);
            maxi= max(currentsum,maxi);

        }//ummmmm
       
        return maxi;
    }
};