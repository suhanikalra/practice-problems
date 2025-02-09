class Solution {
private:
    void solve(int i, vector<int>& nums, int ans, int& result) {
        if(i == nums.size()) {
            result += ans;
            return;
        }
        
        // include
        solve(i + 1, nums, ans ^ nums[i], result);
        
        // exclude 
        solve(i + 1, nums, ans, result);
    }
    
public:
    int subsetXORSum(vector<int>& nums) {
        int result = 0;
        solve(0, nums, 0, result);
        return result;
    }
};