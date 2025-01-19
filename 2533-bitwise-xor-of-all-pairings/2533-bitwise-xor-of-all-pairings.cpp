class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        if(nums1.size()%2==0 and nums2.size()%2==0)return 0;
        else if(nums1.size()%2==1 and nums2.size()%2==0){for(auto k: nums2)ans= ans^k;}
        else if(nums2.size()%2==1  and nums1.size()%2==0){for(auto k: nums1)ans= ans^k;}
        else {for(auto k: nums1)ans= ans^k;for(auto k: nums2)ans= ans^k;}
        return ans;
    }
};