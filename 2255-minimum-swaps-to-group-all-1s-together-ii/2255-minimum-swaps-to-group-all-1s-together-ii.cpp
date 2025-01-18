class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int one=0;int n=nums.size();
        for(auto k: nums){if(k==1)one++;}    
int windowone=0;int start=0;int maxi=0;
        for(int end=0;end<one;end++){
            if(nums[end]==1)windowone++;
        }
        maxi=max(maxi,windowone);
for (int end = one; end < n + one; end++) {
            if (nums[end % n] == 1) windowone++; 
            if (nums[start % n] == 1) windowone--;
            start++;
            maxi=max(maxi,windowone);
        } 
        return one-maxi;  
    }
};