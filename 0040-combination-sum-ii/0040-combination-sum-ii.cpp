class Solution {
public:

vector<vector<int>>ans;
void solve( int start,vector<int>& candidates, int target,vector<int>res ){
     if (target == 0) {
        ans.push_back(res);
        return;
    }

    for (int i = start; i < candidates.size(); i++) {

        if (i > start && candidates[i] == candidates[i - 1]) continue;

        if (candidates[i] > target) break;

        res.push_back(candidates[i]);
        solve(i + 1, candidates, target - candidates[i], res);
        res.pop_back();
    }

}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort( candidates.begin(),candidates.end());

        vector<int>res;
        solve(0, candidates,target,res);
        return ans;
    }
};