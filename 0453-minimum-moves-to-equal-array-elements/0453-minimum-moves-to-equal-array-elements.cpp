class Solution {
public:
    int minMoves(vector<int>& nums) {
      
       int count=0;
        
         
            for(auto k: nums){
                count= count+ abs(k-*min_element(nums.begin(),nums.end()));
            }
        
        return count;
    }
};