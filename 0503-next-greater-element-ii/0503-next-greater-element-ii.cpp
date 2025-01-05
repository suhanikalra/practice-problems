class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(), -1);
        int n = nums.size();

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() and st.top() <= nums[i%n]) {
                st.pop();
            }
            if (!st.empty() and st.top() > nums[i%n] and i<n) {
                ans[i] = st.top();
            }
            st.push(nums[i % n]);
        }

        return ans;
    }
};