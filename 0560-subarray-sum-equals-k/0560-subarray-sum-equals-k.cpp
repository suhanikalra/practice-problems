class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int x=0;
        unordered_map<int,int>mp;
        mp[0]=1;int count=0;
       
        for(auto num: nums){
            x=x+num;
            if(mp.find(x-k)!=mp.end())count+=mp[x-k];
            mp[x]++;
        }
        return count;
        

    }
};
