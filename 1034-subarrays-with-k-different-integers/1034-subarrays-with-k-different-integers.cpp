class Solution {
public:
int solve(vector<int>& nums, int k){
    int start=0;int end=0;unordered_map<int,int>mp;
    int count=0;
        while(end<nums.size()){
            mp[nums[end]]++;
            while(mp.size()>k){
                mp[nums[start]]--;
                if(mp[nums[start]]==0)mp.erase(nums[start]);
                start++;
            }
            count += end - start + 1;
            end++;

        }return count;
    
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return solve(nums,k)-solve(nums,k-1);}
};