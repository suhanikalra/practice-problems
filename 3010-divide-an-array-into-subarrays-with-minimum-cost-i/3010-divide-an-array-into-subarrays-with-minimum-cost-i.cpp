class Solution {
public:
    int minimumCost(vector<int>& nums) {
        if(nums.size()<3)return -1;
        int sum=0;
        sum+=nums[0];
        int min1 = 100; 
        int min2 = 100;

        for( int i=1;i<nums.size();i++){
            if(nums[i] < min1){
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] < min2){
                min2 = nums[i];
            }
            

        }
        return sum+min1+min2;
    }
};