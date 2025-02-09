class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count=0;unordered_map<int,long long>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]-i]++;
        }
        for(auto k: mp){
            count+=k.second*(k.second-1)/2;
        }
        return nums.size()*(nums.size()-1)/2-count;
           
    }
};