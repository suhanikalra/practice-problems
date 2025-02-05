class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int>ans(length,0);
        for(auto k: updates){
            int start= k[0];
            int end= k[1];
            ans[start]=ans[start]+ k[2];
           if(end+1<length) ans[end+1]=ans[end+1]- k[2];
        }
         vector<int>res(length,0);
         res[0]= ans[0];
         for(auto i=1;i<length;i++){
            res[i]= ans[i]+res[i-1];
         }
         return res;


    }
};