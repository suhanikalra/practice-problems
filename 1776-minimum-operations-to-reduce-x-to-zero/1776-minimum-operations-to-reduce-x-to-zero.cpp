class Solution {
public:
    int solve(vector<int>& nums, long long& sum) {
        int start = 0, end = 0;
        long long curr = 0;
        int maxi = 0;
        
        while (end < nums.size()) {
            curr += nums[end]; 
            while (curr > sum && start <= end) {
                curr -= nums[start];
                start++;
            }
            if (curr == sum) {
                maxi = max(maxi, end - start + 1);
            }
            end++;
        }
        
        return maxi;
    }

    int minOperations(vector<int>& nums, int x) {
        long long sum = 0;
        for (auto k : nums) {
            sum += k;
        }
        if (sum < x) return -1;
        sum -= x;
        
        int longestSubarray = solve(nums, sum);
        if (longestSubarray == 0 && sum != 0) return -1; 
        
        return nums.size() - longestSubarray;
    }
};
