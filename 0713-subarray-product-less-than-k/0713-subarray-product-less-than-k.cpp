class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;long long prod=1;
        int start=0;int end=0;
        while(end<nums.size()){
            prod=prod*nums[end];
            while(start<end and prod>=k){
                prod=prod/nums[start];
                start++;
            }
            if(prod<k)
            count+= end-start+1;
            end++;

        }
        return count;

    }
};