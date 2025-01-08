class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
         if (k <= 1) return 0;
        int start=0,end=0;
        long long  mult= 1,count=0;
        while(end<nums.size()){
           mult= mult* nums[end];

            while (start <= end && mult >= k){
                mult= mult/nums[start];start++;
            }

            count+=end-start+1;end++;

        }
        return count;
    }
};