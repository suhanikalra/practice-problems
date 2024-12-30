class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     set<int>st;
       for(auto k: nums)st.insert(k);
       nums.clear();int i=0;
       for(auto k: st)nums.push_back(k);
       return nums.size();
    }
};