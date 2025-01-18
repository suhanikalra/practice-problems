class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int one=0;int n=nums.size();
        for(auto k: nums){if(k==1)one++;}    
int window=0;int start=0;int maxi=0;
        for(int end=0;end<one;end++){
            if(nums[end]==0)window++;
        }
        maxi=max(maxi,window);
for (int end = one; end < n + one; end++) {
            if (nums[end % n] == 0) window++; 
            if (nums[start % n] == 0) window--;
            start++;
            maxi=min(maxi,window);
        } 
        return maxi;  
    }
};