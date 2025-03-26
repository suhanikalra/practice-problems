class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        if(grid.size()==1 and grid[0].size()==1){return 0;}
        vector<int>nums(grid.size()*grid[0].size());int i=0;
        for(auto k: grid){
           for(auto p: k){
            nums[i++]=p;
           }}
           sort(nums.begin(),nums.end());
           auto median= nums[(nums.size())/2];
           cout<<median;
int ans=0;
           for(auto k: nums){
            if(abs(k-median)<x and k!=median or abs(k-median)%x!=0)return -1;
            else ans+=abs(k-median)/x;
           }


return ans;


    }


};