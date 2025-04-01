class Solution {
public:
void solve(int i,vector<int>& nums, int target,int &count){
    if(i == nums.size()) {
            if(target == 0) count++;
            return;
        }
    if(target < 0) return;
    solve(i+1,nums,target-nums[i],count);
    solve(i+1,nums,target,count);

}
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;int count=0;
        for(auto k : nums)sum+=k;
        if(abs(target) > sum || (sum + target) % 2 != 0) return 0;
        solve(0,nums,(target+sum)/2,count);
        return count;
    }
};