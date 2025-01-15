class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int currMaxSum = 0;
        int currMinSum = 0;
        int maxSum = nums[0];
        int minSum = nums[0];
        
        for (int num : nums) {
            totalSum += num;
            
            currMaxSum = max(num, currMaxSum + num);
            maxSum = max(maxSum, currMaxSum);
            
            currMinSum = min(num, currMinSum + num);
            minSum = min(minSum, currMinSum);
        }
        
        if (maxSum < 0) {
            return maxSum;
        }
        
        
        return max(maxSum, totalSum - minSum);
    }
};