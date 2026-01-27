class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0];
        int currsum=nums[0];
        for( int i=1; i<nums.size() ;i++){
            if( currsum<0)currsum=0;
            currsum=nums[i]+currsum;
            maxsum=max(currsum,maxsum);
        }
        return maxsum;
    }
};