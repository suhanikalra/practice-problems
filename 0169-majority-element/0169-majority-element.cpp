class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mid= nums.size()/2;
        sort(nums.begin(),nums.end());
        return nums[mid];
        
    }
};