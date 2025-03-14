class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    set<int>st;
    for(auto k:nums){
        st.insert(k);
    }long long prev=-10000000000;int count=1;int maxi=0;
    for(auto k: st){
        if(k-prev==1)count++;
        else count=1;
        prev=k;
        maxi= max(count,maxi);
    }
    return maxi;
}
};