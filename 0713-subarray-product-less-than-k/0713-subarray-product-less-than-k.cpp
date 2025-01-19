class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
        int start=0,end=0,count=0,prod=1;

        while(end<nums.size()){
            prod=prod*nums[end];
            while(prod>=k){
                prod=prod/nums[start];
                start++;
            }
            if(prod<k){
                count+=end-start+1;

            }end++;


        }
        return count;
        
    }
};