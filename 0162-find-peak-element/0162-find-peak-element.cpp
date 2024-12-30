class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Handle single element case
        if (nums.size() == 1) return 0;
        
        int low = 0;
        int high = nums.size() - 1;
        
        if (nums[0] > nums[1]) return 0;
        if (nums[high] > nums[high-1]) return high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (mid > 0 && mid < nums.size()-1 && 
                nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                return mid;
            }
            
           
            if (mid < nums.size()-1 && nums[mid] < nums[mid+1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return 0;  }
};