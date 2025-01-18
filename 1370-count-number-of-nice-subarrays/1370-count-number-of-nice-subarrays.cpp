class Solution {
public:
int solve(vector<int>& nums, int k){
          int start=0,end=0,odd=0,count=0;
        while(end<nums.size()){
            if(nums[end]%2==1)odd++;
            while(odd>k and start <=end){
                if(nums[start]%2==1)odd--;
                start++;
            }
            count+=end-start+1;end++;
        }
        return count;
        
    
}
    int numberOfSubarrays(vector<int>& nums, int k) {
  return solve(nums,k)-solve(nums,k-1);}
};