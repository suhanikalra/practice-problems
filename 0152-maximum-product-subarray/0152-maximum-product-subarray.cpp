class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax=nums[0];
        int currMin= nums[0];
        int result = nums[0];

        
        for( int i=1;i<nums.size();i++){
            int tempMax = currMax;
            int tempMin = currMin;

            currMax=max({nums[i], tempMax * nums[i], tempMin * nums[i]});
            currMin = min({nums[i], tempMax * nums[i], tempMin * nums[i]});
            result= max( result,currMax);


        }return result;
    }
};