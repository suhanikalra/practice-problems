class Solution {
public:   
    int minOperations(int n) {
        vector<int>nums(n,-1);
      for(int i=0;i<n;i++){
        nums[i]=2*i+1;
      }
       int sum=0;int count=0;
       
        int median= nums[nums.size()/2];
        
         
            for(auto k: nums){
                count= count+ abs(k-median);
            }
        
        return count/2;

        
    }
};