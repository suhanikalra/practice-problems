class Solution {
public:
    int numTeams(vector<int>& nums) {
        int count=0;
        for(int i= 0;i<nums.size()-2;i++){
            for(int j= i+1;j<nums.size()-1;j++){
                for(int k= j+1;k<nums.size();k++){
                    if((nums[i]<nums[j] and nums[j]<nums[k] )|| (nums[i]>nums[j] and nums[j]>nums[k]))count++;
                }}
           
        }return count;
    }
};