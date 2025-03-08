class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int k= nums[i];
            if(mp.find(target-k)!= mp.end()){
                ans.push_back(i);
                ans.push_back(mp[target-k]);
            }
            mp[k]=i;
        }
        return ans;
        
    }
};