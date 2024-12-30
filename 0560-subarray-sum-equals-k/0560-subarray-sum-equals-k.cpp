class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefixsum;
       int sum= 0;int count=0;
        prefixsum[0]=1;
        for(auto num: nums){
            sum+=num;
            if(prefixsum.find(sum-k)!=prefixsum.end()){count=count+prefixsum[sum-k];}
            prefixsum[sum]++;
        }
        return count;
        
    }
};