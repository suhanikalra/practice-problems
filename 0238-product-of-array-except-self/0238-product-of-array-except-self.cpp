class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n, 1); 
        vector<int> pre(n, 1);  
        vector<int> ans(n, 1); 

        
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = nums[i] * pre[i - 1];
        }

       
        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = nums[i] * suff[i + 1];
        }

        
        for (int i = 0; i < n; i++) {
            int prefix = (i == 0) ? 1 : pre[i - 1]; 
            int suffix = (i == n - 1) ? 1 : suff[i + 1]; 
            ans[i] = prefix * suffix;
        }

        return ans;
    }
};
