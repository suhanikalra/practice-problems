class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       vector<int>pre(nums.size(),-1);
       pre[0]= nums[0];int sum=0;
       for(int i= 1;i<nums.size();i++){
        pre[i]=nums[i]+pre[i-1];
       }
       for(auto k:nums)sum+=k;
       for(int i=0;i<nums.size();i++){
        if(pre[i]-nums[i]==(sum-pre[i]))return i;
       }
       return -1;

    }
};