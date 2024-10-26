#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int i = 0;

        for (auto num : nums) {
            mp[num] = i++;
        }

        for (int j = 0; j < nums.size(); j++) {
            int complement = target - nums[j];
            if (mp.find(complement) != mp.end() && mp[complement] != j) {
                return {j, mp[complement]};
            }
        }

        return {};
    }
};
