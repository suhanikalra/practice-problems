class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> result;
        for (int i = 0; i < nums.size() - 2; i++) {
            int start = i + 1;
            int end = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            while (start < end) {
                if (nums[start] + nums[end] == -nums[i]) {
                    result.push_back(nums[i]);
                    result.push_back(nums[start]);
                    result.push_back(nums[end]);
                    ans.push_back(result);
                    result.clear();
                }
                if (nums[start] + nums[end] > -nums[i])
                    end--;
                else
                    start++;
            }
        }
        set<vector<int>> st;
        for (auto s : ans) {
            st.insert(s);
        }
        ans.clear();
        for (auto s : st) {
            ans.push_back(s);
        }

        return ans;
    }
};