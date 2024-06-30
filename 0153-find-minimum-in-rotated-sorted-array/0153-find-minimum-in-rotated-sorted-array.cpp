class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        
        while (start < end) {
            // If the array is sorted (not rotated), return the first element
            if (nums[start] < nums[end]) {
                return nums[start];
            }
            
            int mid = start + (end - start) / 2;
            
            // Check if nums[mid] is the minimum element
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }
            
            // Determine which half to continue searching
            if (nums[mid] >= nums[start]) {
                start = mid + 1; // Minimum element is in the right half
            } else {
                end = mid - 1; // Minimum element is in the left half
            }
        }
        
        // The minimum element is nums[start] or nums[end] (they are equal at this point)
        return nums[start];
    }
};
