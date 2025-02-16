class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;int high= nums.size()-1;
        int n = nums.size();
        if (n == 1) return nums[0];
        while(low<=high){
            int mid= (high-low)/2+low;
            if(mid%2==0){
                if(mid + 1 < n &&nums[mid]==nums[mid+1])low=mid+2;
                else if(mid > 0 and nums[mid]==nums[mid-1])high= mid-2;
                else return nums[mid];
            }
          else {
                
                if (mid > 0 && nums[mid] == nums[mid - 1]) {
                   
                    low = mid + 1;
                }
                else if (mid + 1 < n && nums[mid] == nums[mid + 1]) {
                    high = mid - 1;
                }
                else {
                    return nums[mid];
                }
            }

        }
        return low;
    }
};