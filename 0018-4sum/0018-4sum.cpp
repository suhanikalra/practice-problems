class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
if(nums.size()<4 )return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            
            for (int j = i + 1; j < nums.size() - 2; j++) {
             long long temp = target;
                int start = j + 1;
                auto end = nums.size() - 1;
                while (start < end) {
                    
                    if (nums[i] + nums[j] == temp-(nums[start] + nums[end] )) {
                        ans.push_back(
                            {nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;
                    } else {
                        if (nums[i] + nums[j]  >
                            temp- (nums[start] + nums[end]))
                            end--;
                        else
                            start++;
                    }
                }
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

        return ans;
    }
};