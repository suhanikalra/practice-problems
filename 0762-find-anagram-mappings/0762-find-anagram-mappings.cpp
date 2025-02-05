class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;int i=0;vector<int>ans;
        for(auto k: nums2){
            mp[k]=i++;
        }
        for(int j=0;j<nums1.size();j++){
            ans.push_back(mp[nums1[j]]);
        }
        return ans;
    }
};