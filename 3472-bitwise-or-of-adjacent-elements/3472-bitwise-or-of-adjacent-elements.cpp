class Solution {
public:
    vector<int> orArray(vector<int>& nums) {
       vector<int>arr; int prev=nums[0];
        for(int i=1;i<nums.size();i++){
            arr.push_back(nums[i] | prev);
            prev= nums[i];
        }
        return arr;
    }
};