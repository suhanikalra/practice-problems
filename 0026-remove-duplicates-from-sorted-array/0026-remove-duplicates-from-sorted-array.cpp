class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        for(auto k: nums){
            st.insert(k);
        }
int i=0;
        for(auto k: st){
            nums[i++]=k;
        }
        return i;
        
    }
};