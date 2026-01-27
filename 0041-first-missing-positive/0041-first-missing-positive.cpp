class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool one= false;
        int n=nums.size();
        for(auto &k:nums){
            if(k==1)one=true;
            if(k>n or k<1){
                k=1;
            }
        }
    if(one==false)return 1;
        for(int i=0;i<nums.size();i++){
            int index= abs(nums[i])-1;
            if(nums[index]>0){
                nums[index]=-nums[index];
            }

        
        }

        for( int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
               return  i+1;
            }
        }
        return n+1;

        
    }
};