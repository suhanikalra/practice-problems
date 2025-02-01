class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int prev=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==prev)return false;
            prev= nums[i]%2;
        }
        return true;
        
    }
};