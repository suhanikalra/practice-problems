class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0)return 0;
        int start=0;int end=0;long long prod=1;int count=0;
        while(end<nums.size()){
            prod= prod*nums[end];
            while(prod>=k  and start<=end){
                prod= prod/nums[start];start++;
            }
            count+=end-start+1;end++;
        }return count;

        
    }
};