class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
       int start=0,end=0,sum=0,mini=INT_MAX;
       while(end<nums.size()){
        sum+=nums[end];
        while(sum>=k){
            mini=min(end-start+1,mini);
            sum=sum-nums[start];start++;
        }
        end++;
       } 
       if(mini==INT_MAX)return 0;
       return mini;
    }
};