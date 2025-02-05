class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
         vector<int>ans(n,0);
       for (auto k : lights) {
            int start = max(0, k[0] - k[1]);  
            int end = min(n - 1, k[0] + k[1]);
            
            ans[start] = ans[start] + 1;
            if (end + 1 < n) ans[end + 1] = ans[end + 1] - 1; 
        }

         vector<int>res(n,0);
         long long count=0;
         res[0]= ans[0];
           if(res[0]>=requirement[0])count++;
          for (int i = 1; i < n; i++) {
            res[i] = ans[i] + res[i - 1];
            if (res[i] >= requirement[i]) count++;
        }
         
         return count;
         
    }
};