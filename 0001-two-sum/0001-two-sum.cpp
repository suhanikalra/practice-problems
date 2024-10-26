class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        unordered_map<int,int> mp;
        for(auto c: nums){
            mp.insert({c,i++});
        }

        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i]) != mp.end() and mp[target-nums[i]] != i ){
                return {i,mp[target-nums[i]]};
            }
        }
       return {};
        
    }
};