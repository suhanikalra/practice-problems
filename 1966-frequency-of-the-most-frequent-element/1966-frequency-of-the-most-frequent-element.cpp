class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int maxFreq = 1;  
        int start = n - 1;  
        int end = n - 1;
        long long operations = 0;  
        
        while (end >= 0) {
            if (end < n - 1) {
                operations +=(nums[start] - nums[end]);
            }
            
            while (operations > k && start > end) {
                operations -= (nums[start] - nums[start-1]) * (start - end);
                start--;
            }
            
            maxFreq = max(maxFreq, start - end + 1);
            end--;
        }
        
        return maxFreq;
    }
};