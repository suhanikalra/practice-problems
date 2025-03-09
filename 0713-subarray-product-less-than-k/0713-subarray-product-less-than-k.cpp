class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0)return 0;
      int count=0;
        int start=0;int end=0;int prod=1;
        while(end<nums.size()){
            prod= prod*nums[end];
            while(prod>=k and start<=end){
                prod=prod/nums[start];
                start++;
            }
            
            count+=end-start+1;
            end++;
        }
        return count;
    }
};