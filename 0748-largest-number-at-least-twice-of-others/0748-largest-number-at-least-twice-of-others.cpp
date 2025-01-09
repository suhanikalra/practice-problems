class Solution {
public:
    int dominantIndex(vector<int>& nums) {
       auto k= max_element(nums.begin(),nums.end());
       int maxi= *k;
       int maxIndex = k - nums.begin();
       int count=0;
       for(auto i: nums){
        if(2*i<=maxi)count++;

       }
   

        return (count == nums.size() - 1) ? maxIndex : -1;
    }
};