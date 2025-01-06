class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int>st;
        set<pair<int,int>>ans;
sort(nums.begin(),nums.end());
        for(auto i: nums){
            if(st.find(i-k)!=st.end())ans.insert({i,i-k});
            st.insert(i);}
        return ans.size();
        
    }
};