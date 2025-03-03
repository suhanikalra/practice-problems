class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        unordered_map<int,vector<int>>mp;
        for (int i=0;i<nums.size();i++){
            if(nums[i]<pivot)mp[0].push_back(nums[i]);
            if(nums[i]>pivot)mp[2].push_back(nums[i]);
            if(nums[i]==pivot)mp[1].push_back(nums[i]);
            
        }int i=0;
        vector<int> res(mp[0].size()+mp[1].size()+mp[2].size(),0);
         if(mp[0].size()>0){
        for(auto k: mp[0]){
           
            res[i++]=k;
        }}
         if(mp[1].size()>0){
        for(auto k: mp[1]){
           
            res[i++]=k;
        }
         }

         if(mp[2].size()>0){
            for(auto k: mp[2]){
           
            res[i++]=k;
        }}
        return res;

    }
};