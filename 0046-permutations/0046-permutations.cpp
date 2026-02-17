class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, vector<int> &nums) {
        if( i==nums.size()){
            ans.push_back(nums);
        }
        for( int index=i;index<nums.size();index++){
            
            swap(nums[i],nums[index]);
            solve(i+1,nums);
            swap(nums[i],nums[index]);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        solve(0, nums);
        return ans;
    }
};