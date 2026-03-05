class Solution {
public:
vector<vector<int>> res;

void solve(int i, vector<int>& candidates, int target,vector<int>ans){
    
    if(i==candidates.size() and target==0){res.push_back(ans);return;}
    if( i== candidates.size())return;

    if(candidates[i]<=target){
        ans.push_back(candidates[i]);
        solve(i,candidates,target-candidates[i],ans);
        ans.pop_back();
        solve(i+1,candidates,target,ans);

    }
    else solve(i+1,candidates,target,ans);

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0,candidates, target,{});
        return res;
    }
};