class Solution { 
    int subsetSum(vector<int>& nums, int idx, int sum,vector<vector<int>>& ans){
        //base cases
      if(idx<0){
          if(sum == 0) return 1;
          else return 0;
      }
        
        if(ans[idx][sum]!=-1) return ans[idx][sum];
        if(nums[idx]>sum){
            return ans[idx][sum] = subsetSum(nums,idx-1,sum,ans);
        }
            
         ans[idx][sum]=subsetSum(nums,idx-1,sum - nums[idx],ans)
             +
             subsetSum(nums,idx-1,sum,ans);
            
        return ans[idx][sum];
        }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // If the total sum is less than the target or (totalSum + target) is odd, there are no valid ways.
        if (totalSum < abs(target) || (totalSum + target) % 2 == 1) {
            return 0;
        }

        int targetSum = (totalSum + target) / 2;

        // Create a DP array to store the number of ways to reach each possible sum.
        int len = nums.size();
        vector<vector<int>> ans(len+1,vector<int>(targetSum+1,-1));

        return subsetSum(nums, len-1, targetSum, ans);

        
    }
};