class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        sort(nums.begin(), nums.end());
        int count = 0;

        int left = 0;
        int right = 1;

        while (right < nums.size()) {
            if (left == right || nums[right] - nums[left] < k) {
                right++;
            } else if (nums[right] - nums[left] > k) {
                left++;
            } else {
                count++;
                left++;
                right++;
               
                while (right < nums.size() && nums[right] == nums[right - 1]) right++;
                while (left < nums.size() && nums[left] == nums[left - 1]) left++;
            }
        }
        
        return count;
    }
};
