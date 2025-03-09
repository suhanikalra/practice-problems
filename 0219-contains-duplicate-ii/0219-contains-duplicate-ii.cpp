class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;int end=0;
        while(end<nums.size()){
            if(mp.find(nums[end])!=mp.end()){if(end-mp[nums[end]]<=k)return true;
            }
         mp[nums[end]]=end;            
            end++;
        }
        return false;

    }
};