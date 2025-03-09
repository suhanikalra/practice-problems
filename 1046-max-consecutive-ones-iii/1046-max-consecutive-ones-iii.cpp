class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0;int end=0;int zero=0;int maxi=0;
        while(start<=end and end<nums.size()){
            if(nums[end]==0)zero++;
            while(zero>k){
                if(nums[start]==0)zero--;
                start++;
            }
            if(zero<=k){
            maxi = max(maxi, end - start + 1);
            end++;

        }}
        return maxi;
 
    }
};