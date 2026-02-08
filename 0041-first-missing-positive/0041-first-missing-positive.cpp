class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int hasOne=0;
       for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) hasOne = true;
            if (nums[i] <= 0 || nums[i] > nums.size())
                nums[i] = 1;
       }
        
       if( hasOne<1)return 1;
       for( int i=0;i<nums.size();i++){
        int index= abs( nums[i])-1;
        if( nums[index]>0)nums[index]=-nums[index];
       }

        for( int i=0;i<nums.size();i++){
            if( nums[i]>0)return i+1;
        }
        return nums.size()+1;

    }
};