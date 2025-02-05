class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        long long ans = 0;
        int start = 0, prev = -1;
        
        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] <= prev) {
                ans += (long long)(end - start) * (end - start + 1) / 2;
                start = end;
                prev = -1;
            }
            prev = nums[end];
        }
        
        ans += (long long)(nums.size() - start) * (nums.size() - start + 1) / 2;
        return ans;
    }
};