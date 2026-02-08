class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;mp[0]=1;
        int start=0;int end= 0;int ans=0;int sum=0;

        while(end<nums.size()){
            sum+=nums[end];
            if( mp.find( (k+sum%k)%k)!=mp.end()){
                ans+=mp[(k+sum%k)%k];
            }
            mp[(sum%k+k)%k]++;end++;
        }
        return ans;
    }
};