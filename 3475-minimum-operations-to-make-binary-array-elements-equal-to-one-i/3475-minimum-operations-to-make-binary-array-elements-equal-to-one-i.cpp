class Solution {
public:
    int minOperations(vector<int>& nums) {
       int count=0,n = nums.size();
        if (nums.size()<2) return -1;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==0){
                nums[i]=1;
                nums[i+1]= abs(1-nums[i+1]);
                nums[i+2]= abs(1-nums[i+2]);
                count++;
            }
            
        }
        if (nums[n-2] != 1 || nums[n-1] != 1) {
            return -1; 
        }
        return count;
    }
};