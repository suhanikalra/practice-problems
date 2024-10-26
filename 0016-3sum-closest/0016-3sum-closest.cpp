class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < nums.size() - 2; i++) {
            int start = i + 1;
            int end = nums.size() - 1;
            
            while (start < end) {
                int currentSum = nums[i] + nums[start] + nums[end];

                if (currentSum == target) {
                    return target;
                } else {
                   
                    if (abs(currentSum - target) < abs(ans - target)) {
                        ans = currentSum;
                    }

                    if (currentSum > target) {
                        end--;
                    } else {
                        start++;
                    }
                }
            }
        }
        return ans;
    }
};
