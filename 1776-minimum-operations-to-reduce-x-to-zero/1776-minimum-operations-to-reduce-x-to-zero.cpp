class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int start=0;int end=0;long long sum=0;int maxi= INT_MIN;long long currentsum=0;
        for(auto k: nums){
            sum+=k;
        }
        if(sum<x)return -1;
        while(end<nums.size()){
            currentsum+=nums[end];
            while(currentsum>sum-x){
                currentsum=currentsum-nums[start];
                start++;
            }
            if(currentsum==sum-x)
            maxi=max(maxi,end-start+1);
            end++;
        }
        if(maxi==INT_MIN)return -1;
        return nums.size()-maxi;
    }
};