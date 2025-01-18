class Solution {
public:
void solve(int i,vector<int>nums,int target,vector<vector<int>> &result,vector<int>&ans){
if(i==nums.size())return;
if(target<0)return;
if(target==0){result.push_back(ans);return;}
ans.push_back(nums[i]);
solve(i,nums,target-nums[i],result,ans);
ans.pop_back();
solve(i+1,nums,target,result,ans);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;vector<int>ans;
        solve(0,nums,target,result,ans);
        return result;

        
    }
};