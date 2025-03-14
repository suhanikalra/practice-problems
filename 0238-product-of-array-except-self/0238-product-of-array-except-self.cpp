class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>pre(nums.size()+1,1);
         vector<int>suffix(nums.size()+1,1);
        pre[0]=1;int i=1;
        for(auto num: nums){
        pre[i++]=pre[i-1]*num;
        }

        for(int i= nums.size()-1;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i];
        }
int j=0;vector<int>ans(nums.size());
        for(int i = 0; i < nums.size(); i++) {
           
            ans[i] = pre[i] * suffix[i + 1];
        }
return ans;

    }
};