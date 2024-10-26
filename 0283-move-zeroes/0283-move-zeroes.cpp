class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    vector<int>arr(nums.size(),0);
    int j=0,i=0;
    while(i<nums.size()){
        if(nums[i] !=0)arr[j++]= nums[i];
        i++;
    }
    nums= arr;
    return;
    }
};