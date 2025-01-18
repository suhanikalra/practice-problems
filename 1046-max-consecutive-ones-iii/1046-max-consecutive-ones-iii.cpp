class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0,end=0;
        int zero=0;int count=0;
        while(end<nums.size()){
            if(nums[end]==0)zero++;
            while(zero>k){
                if(nums[start]==0){zero--;}start++;
            }
            count=max(end-start+1,count);end++;
        }
        return count;
        
    }
};