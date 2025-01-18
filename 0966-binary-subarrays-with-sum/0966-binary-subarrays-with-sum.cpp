class Solution {
public:
int solve(vector<int>&nums,int goal){
     int start=0,end=0;
        int count=0;int sum=0;
        while(end<nums.size()){
            sum+=nums[end];
            while(sum>goal  && start <= end){
                sum=sum-nums[start];
                start++;
            }
            count+=end-start+1;
            end++;

        }
        return count;
    
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }
};