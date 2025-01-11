class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum=0;int maxi= INT_MIN;long long total=0;
        for(auto k: nums)sum+=k;
        if(sum<x)return -1;

        int start=0;int end=0;
        while(end<nums.size()){
            total+=nums[end];
            while(total>sum-x){
                total=total-nums[start];
                start++;

            }
            if(total== sum-x){
                maxi=max(maxi,end-start+1);}end++;
            
        }
if(maxi==INT_MIN)return -1;
        return nums.size()-maxi;        
    }
};