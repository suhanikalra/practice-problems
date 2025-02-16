class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans=0;
        for(auto k: nums)
{
ans= ans^k;
}    return ans;    
    }
};