class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        sort(nums.begin(), nums.end());
        int count = 0;

        int left = 0;
        int right = 1;

        while (left<=right and right<nums.size()) {
            if (left == right || nums[right] - nums[left] < k) {
                right++;
            } else if (nums[right] - nums[left] > k) {
                left++;
            } else {
                count++;
               
               
                while (right+1 < nums.size() && nums[right] == nums[right + 1]) right++;
                while (left+1 < nums.size() && nums[left] == nums[left + 1]) left++;

                 left++;
                right++;
            }
        }
        
        return count;
    }
};
