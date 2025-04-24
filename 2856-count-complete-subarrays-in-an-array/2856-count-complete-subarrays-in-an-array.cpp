class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>s;for(auto K: nums){s.insert(K);}int n= nums.size();
        int k= s.size();int count=0;
        unordered_map<int,int>mp;int start=0,end=0;
        for(;end<nums.size();end++){
            mp[nums[end]]++;
            while(mp.size()==k){
                 count += n - end;
                mp[nums[start]]--;
                if(mp[nums[start]]==0) mp.erase(nums[start]);
                start++;
            }
            
       
        }
        return count;
        
    }
};