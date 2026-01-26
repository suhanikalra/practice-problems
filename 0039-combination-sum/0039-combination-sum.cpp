class Solution {
public:
    vector<vector<int>>ans;
    void solve( int i,vector<int>& candidates, int target,vector<int>res){
        if(i>=candidates.size()  or target<0)return ;
        if(target==0){ans.push_back(res);return;}
        res.push_back(candidates[i]);
        solve(i,candidates,target-candidates[i],res);
        res.pop_back();
        solve(i+1,candidates,target,res);


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>res;
        solve(0,candidates,target,res);
        return ans;
    }
};