class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto k: nums)mp[k]++;
        for(auto &[x,y]: mp){if (y==1)return x;}
        return -1;
        
    }
};