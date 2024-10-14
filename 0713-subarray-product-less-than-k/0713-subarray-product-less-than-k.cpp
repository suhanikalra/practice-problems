class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
      
        long long ans=1,count=0;
        int start=0; int end=0;
        for (end;end<n;end++){
            ans*=nums[end];
            while(end>start and ans>=k ){
                ans= ans/nums[start++];
                

            }if(ans<k){
 count += (end - start + 1);}

        }
        return count;
    }
};