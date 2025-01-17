class Solution {
public:
void solve(int i,vector<int>& nums,vector<int>& ans, vector<vector<int>>&result){
    if(i==nums.size()){result.push_back(ans);return ;}
    ans.push_back(nums[i]);solve(i+1,nums,ans,result);
    ans.pop_back();
    solve(i+1,nums,ans,result);

}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>> result;
        solve(0,nums,ans,result);
        return result;
    }
};