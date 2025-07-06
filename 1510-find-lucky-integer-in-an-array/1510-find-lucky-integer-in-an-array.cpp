class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>freq(501,0);
        for(auto k: arr){
            freq[k]++;
        }
        int ans=-1;
        for (int i = 1; i <= 500; ++i) {  
            if (freq[i] == i)              
                ans = max(ans, i);
        
        }
        
        return ans;
    }
};