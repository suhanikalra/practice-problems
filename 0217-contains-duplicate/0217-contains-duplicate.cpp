class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int prev=-1;
        for(auto k: nums){
            if(prev==k)return true;
            prev=k;
        }
        return false;
        
    }
};