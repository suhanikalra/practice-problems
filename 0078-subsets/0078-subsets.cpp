class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        helper(nums, res, curr, 0);
        return res;
    }
private:
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int idx) {
        if (idx == nums.size()) {
            res.push_back(curr);
            return;
        }
        
  
        curr.push_back(nums[idx]);
        helper(nums, res, curr, idx + 1);
        curr.pop_back();


        helper(nums, res, curr, idx + 1);
        
    }
};
