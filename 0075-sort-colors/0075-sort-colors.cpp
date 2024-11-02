class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int zero=0,ones=0,two=n-1;
        while(ones<=two){
           if(nums[ones]==0){swap(nums[zero],nums[ones]);
           zero++;
           ones++;}
           else if (nums[ones]==2){swap(nums[ones],nums[two]);
           two--;}
           else ones++;

        }
        return;
        
        
    }
};