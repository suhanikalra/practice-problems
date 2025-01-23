
class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int,int>mp;
        for(auto k: word){
            mp[k]++;  
        }
        vector<int>nums;
        for(auto k: mp){
            nums.push_back(k.second);
        }
        int count=0;
        sort(nums.begin(),nums.end(),greater<int>());
 for (int num : nums) {
      
    }    
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i] * ((i / 8) + 1);
           
        }

return count;

    
    }
};