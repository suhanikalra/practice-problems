class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        ans.push_back(mp.size());
        for(int i = k; i < nums.size(); i++) {
            mp[nums[i-k]]--;
            if(mp[nums[i-k]] == 0) {
                mp.erase(nums[i-k]);
            }
            mp[nums[i]]++;
            
            ans.push_back(mp.size());
        }
        return ans;
    }
};