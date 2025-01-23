class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto k: nums){
            mp[k]++;
        }int ans;
        for(auto k: mp){
            ans= ans+k.second*(k.second-1)/2;
        }
        return ans;
    }
};