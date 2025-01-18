class Solution {
public:
    void solve(int i, vector<int>& nums, int target, vector<vector<int>>& result, vector<int>& ans, int k) {
        if (target < 0 || ans.size() > k) return; 
        if (target == 0 && ans.size() == k) { 
            result.push_back(ans);
            return;
        }
        if (i == nums.size()) return; 

        
        ans.push_back(nums[i]);
        solve(i + 1, nums, target - nums[i], result, ans, k);
        ans.pop_back(); 
       
        solve(i + 1, nums, target, result, ans, k);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for (int i = 1; i <= 9; i++) {
            nums.push_back(i); 
        }

        vector<vector<int>> result;
        vector<int> ans;
        solve(0, nums, n, result, ans, k);
        return result;
    }
};
