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
        res.insert(curr);  
        
        for (int i = idx; i < nums.size(); ++i) {
            curr.push_back(nums[i]);  
            helper(nums, res, curr, i + 1);  
            curr.pop_back();
        }
    }
};