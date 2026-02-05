class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int low = 0, high = nums.size() - 1;
        int mid;
        while (low <= high) {
            mid = (high - low) / 2 + low;
            if (nums[mid] == target){
                return true;
            }
            if(nums[mid]==nums[low] && nums[mid]==nums[high])
            {
                low++;
                high --;
                continue;
            }
             if (nums[mid] >nums[high]){
                //left half sorted
                if( nums[low]<=target and target<nums[mid]){
                    high= mid-1;
                }
                else low= mid+1;}
            else{
                //right half sorted
                if( nums[mid]<target and target<=nums[high]){
                    low= mid+1;
                }
                else high= mid-1;

            


        }

    }
    return false;
    }
};