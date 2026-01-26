class Solution {
public:
vector<vector<int>>ans;
    void solve(int index,vector<int>& nums,vector<int> res){
        if(index==nums.size()){ans.push_back(res);return;}
        res.push_back(nums[index]);
        solve( index+1,nums,res);
        res.pop_back();
        solve( index+1,nums,res);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n= nums.size();
        vector<int>res;
        solve(0,nums,res);
        return ans;
    }
};