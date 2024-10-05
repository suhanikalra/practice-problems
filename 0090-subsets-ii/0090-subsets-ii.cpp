class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        helper(nums, res, curr, 0);
         return vector<vector<int>>(res.begin(), res.end());
       
    }
private:
   void helper(vector<int>& nums,set<vector<int>> &res, vector<int>& curr, int idx) {
        res.insert(curr);  // Add current subset to the result
        
        for (int i = idx; i < nums.size(); ++i) {
            // Skip duplicate elements
       
            
            curr.push_back(nums[i]);  // Include nums[i] in the current subset
            helper(nums, res, curr, i + 1);  // Recurse for further elements
            curr.pop_back();  // Backtrack
        }
    }
};