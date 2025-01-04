class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int odd=nums.size()-1;
        int even=0;

        while(even<=odd){
            if(nums[even]%2==1){swap(nums[odd],nums[even]);odd--;}
            else if(nums[even]%2==0) {even++;}
  

        }
        return nums;
    }
};