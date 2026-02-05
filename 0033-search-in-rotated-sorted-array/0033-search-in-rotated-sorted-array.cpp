class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int mid;
        while (low <= high) {
            mid = (high - low) / 2 + low;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > nums[high]) {
                //lefy sorted
                if (nums[mid] > target && target >= nums[low]) {
                    high = mid - 1;
                } else
                    low = mid + 1;
            } else 
            ///right sorted
            {
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};