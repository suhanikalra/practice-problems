class Solution {
public:
    bool solve(vector<int>& nums, int k, int maxSumAllowed) {
        int sum = 0, count = 1;  // Start with 1 subarray (since there's always at least 1)
        
        for (auto num : nums) {
            sum += num;
            if (sum > maxSumAllowed) {  // Need to split
                sum = num;  // Start a new subarray
                count++;    // Increment the subarray count
            }
        }
        
        return count > k;  // Return true if we need more than k subarrays
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());  // At least the largest element
        int high = accumulate(nums.begin(), nums.end(), 0);  // At most the sum of all elements
        int ans = high;  // To store the result

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (solve(nums, k, mid)) {  // If we need more than k subarrays, increase mid
                low = mid + 1;
            } else {  // Otherwise, it's a valid solution, try for a smaller max sum
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};
