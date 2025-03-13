class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto k:nums){
            mp[k]++;if(mp[k]>1)return true;
        }
        return false;
        
    }
};