class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto k: arr){
            mp[k]++;
        }
        unordered_set<int>st;
        for(auto k: mp){
            st.insert(k.second);
        }
        return st.size()==mp.size();

        
    }
};