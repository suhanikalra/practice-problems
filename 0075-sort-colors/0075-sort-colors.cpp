class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int zero=0,ones=0,two=0;
        for(auto num: nums){
            if(num==0)zero++;
            if(num==1)ones++;
            if(num==2)two++;
        }
        int i=0;
        
            while(zero--){
                nums[i++]=0;
                
            }
            while(ones--){
                nums[i++]=1;
            }
            while(two--){
                nums[i++]=2;
            }
        
        return;
        
    }
};