class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
         long long MOD = 1000000007;
        long long ans=1;int i=0;long long count=0;
        while(i<nums.size() and nums[i]==0){
            i++;
        } if (i == nums.size()) return 0;
        for( ;i<nums.size();i++){
           
            if(nums[i]==1){ans=(ans*(count+1))%MOD;count=0;}
            else count++;
        }
        return ans;


        
    }
};