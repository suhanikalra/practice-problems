class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        set<int>st;

        for(auto k:nums1){
            mp1[k]++;

        }
        for(auto k:nums2){
            mp2[k]++;

        }
        vector<int>ans;
        for(auto k:nums2){
            if(mp1[k]  and st.find(k)==st.end()){
                // count+=mp1[k];
                int f= min(mp1[k],mp2[k]);
                for(int i=0;i<f;i++){ans.push_back(k);}
                st.insert(k);
            }
           

        }
        return ans;
       



    }
};