class Solution {
public:
    int findMin(vector<int>& nums) {
        int low= 0;
        int high=nums.size()-1;
        int mid= ( high-low)/2+low; 
        int ans=-1;
        while( low<high){
            mid= ( high-low)/2+low;
            if( nums[mid]<nums[high]){
                //right half is sorted
                ans= nums[mid];
                high= mid;
            }
            else{
                low= mid+1;
            }
        }
        return nums[low];
    }
};