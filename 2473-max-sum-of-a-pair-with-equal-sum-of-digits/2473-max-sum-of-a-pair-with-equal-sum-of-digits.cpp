#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            int num = nums[i];
            while (num > 0) {
                sum += num % 10; 
                num /= 10;
            }
            mp[sum].push_back(i); 
        }

        int ans = -1; 

        for (auto& [sum, indices] : mp) {
            if (indices.size() >= 2) {
                sort(indices.begin(), indices.end(), [&nums](int a, int b) {
                    return nums[a] > nums[b];
                });
                ans = max(ans, nums[indices[0]] + nums[indices[1]]);
            }
        }

        return ans;
    }
};