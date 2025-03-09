class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int start = 0, maxFreq = 0;
        long long sum = 0; 
        for (int end = 0; end < nums.size(); end++) {
            sum += nums[end]; 

            while ((long long)(end - start + 1) * nums[end] - sum > k) {
                sum -= nums[start]; 
                start++; 
            }

            maxFreq = max(maxFreq, end - start + 1); 
        }
        
        return maxFreq;
    }
};
