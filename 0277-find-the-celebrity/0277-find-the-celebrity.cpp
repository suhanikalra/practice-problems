/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int i=0;int j=n-1;
        while(i<j){
            if( knows(i,j)==1)i++;
            else j--;
        }
        auto ans=i;
      
        for (int k = 0; k < n; ++k) {
            if (k == ans) continue;
            if (knows(ans, k) || !knows(k, ans))
                return -1;
        }
        return ans;
        
    }
};