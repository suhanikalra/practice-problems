class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;int high=nums.size()-1;
        int mid=0;int ans=0;
        while(low<=high){
            mid= (high-low)/2+low;
            if(nums[mid]==target)return ans= mid;
            else if(nums[mid]>target){ans=mid;high=mid-1;}
            else{ low=mid+1;ans=mid+1;}
        }
        return ans;
        
    }
};