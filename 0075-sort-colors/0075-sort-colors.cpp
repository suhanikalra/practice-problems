class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one=0,zero=0,two=nums.size()-1;

        while( one<= two){
            if( nums[one]==0){swap( nums[one],nums[zero]);zero++;one++;}
            else if(nums[one]==2){ swap( nums[one],nums[two]);two--;}
            else{ one++;}

        }
    }
};