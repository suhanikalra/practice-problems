class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int start = 0, end = 0;
        long long maxSum = 0, currentSum = 0;
        unordered_map<int, int> mp;
        
        while (end < nums.size()) {
            currentSum += nums[end];
            mp[nums[end]]++;

            if (end - start + 1 > k) {
                currentSum -= nums[start];
                mp[nums[start]]--;
                if (mp[nums[start]] == 0) {
                    mp.erase(nums[start]);
                }
                start++;
            }

            if (end - start + 1 == k && mp.size() == k) {
                maxSum = max(maxSum, currentSum);
            }

            end++;
        }

        return maxSum;
    }
};
