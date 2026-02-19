class Solution {
public:
    vector<vector<int>> res;
    void solve(int i, vector<int>& candidates, int target, vector<int>& ans) {
        if (target == 0) {
            res.push_back(ans);
            return;
        }
        if (target < 0 or i == candidates.size())
            return;
        if (candidates[i] <= target) {
            ans.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], ans);
            ans.pop_back();
        } 
            solve(i + 1, candidates, target , ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        solve(0, candidates, target, ans);
        return res;
    }
};