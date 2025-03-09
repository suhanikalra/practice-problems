class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefix;int sum=0;int count=0;
        prefix[0]=1;
        for(auto num: nums){
            sum+=num;
            if(prefix.find(sum-k)!=prefix.end())count+=prefix[sum-k];
            prefix[sum]++;
        }
        return count;
    }
};