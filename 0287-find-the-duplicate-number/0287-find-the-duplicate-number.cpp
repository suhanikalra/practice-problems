class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      unordered_map<int,int>freq;
      for(auto num: nums){
        freq[num]++;
      }
      for(auto num:nums){
        if(freq[num]>1)
        return num;
      }
      return -1;
    }
};