class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                mp[nums[i]*nums[j]]++;
            }
        }
int ans=0;
        for(auto k: mp){ 
            ans += k.second * (k.second - 1) / 2 * 8;        }
        return ans;
        
    }
};