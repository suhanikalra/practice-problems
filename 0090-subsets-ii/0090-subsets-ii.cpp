class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        helper(nums, res, curr, 0);
        return res;
       
    }
private:
   void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int idx) {
        res.push_back(curr);  // Add current subset to the result
        
        for (int i = idx; i < nums.size(); ++i) {
            // Skip duplicate elements
            if (i > idx && nums[i] == nums[i - 1]) continue;
            
            curr.push_back(nums[i]);  // Include nums[i] in the current subset
            helper(nums, res, curr, i + 1);  // Recurse for further elements
            curr.pop_back();  // Backtrack
        }
    }
};