class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int median= nums[nums.size()/2];
       int sum=0;int count=0;
        
         
            for(auto k: nums){
                count= count+ abs(k-median);
            }
        
        return count;
    }
};