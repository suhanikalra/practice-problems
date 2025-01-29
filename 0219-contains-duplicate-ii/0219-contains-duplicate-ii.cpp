class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int t) {
       map<int,vector<int>>mp;int i=0;
       for(auto num: nums){
        mp[num].push_back(i++);
       }
       for(auto k: mp){
for(int i=1;i<k.second.size();i++){
    if(k.second[i]-k.second[i-1]<=t)return true;
}

       }
       return false;
    }
};