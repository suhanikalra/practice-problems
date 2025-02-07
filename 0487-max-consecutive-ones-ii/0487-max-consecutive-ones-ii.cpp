class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int start=0;int end=0;int zero=0;int maxi=INT_MIN;
        while(end<nums.size()){
            if(nums[end]==0)zero++;
            while(zero>1){
                if(nums[start]==0){zero--;}
                start++;

            }
            maxi=max(end-start+1,maxi);end++;

        }
        return maxi;
    }
};