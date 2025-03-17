class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;
       for( auto k: nums){
        mp[k]++;

       }
        
        for(auto &[x,y]: mp){
            if(y%2==1)return false;
        }
        return true;
    }
};