class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0;
        int end= 0,ans=0;
        int countzero=0;
        for(int end=0;end<nums.size();end++){
           if(nums[end]==0)countzero++;
           while(countzero>k){ 
            if(nums[start]==0)countzero--;
           start++;}
           ans= max(end-start+1,ans);
        }
        return ans;
    }
};