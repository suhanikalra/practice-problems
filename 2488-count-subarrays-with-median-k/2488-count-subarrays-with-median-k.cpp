class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;int i=0;
        mp[0] = 1; int sum=0;int ans=0;
        for(;i<nums.size();i++){
            auto num= nums[i];
            if(num>k)sum++;
            if(num<k)sum--;
            if(num==k)break;
            mp[sum]++;
        }
        for(;i<nums.size();i++){
            auto num= nums[i];
            if(num>k)sum++;
            if(num<k)sum--;
            ans=ans+ mp[sum]+mp[sum-1];

        }
        return ans;

    }
};