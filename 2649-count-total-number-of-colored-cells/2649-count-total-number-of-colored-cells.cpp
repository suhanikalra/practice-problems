class Solution {
public:
    long long coloredCells(int n) {
        long long sum=1;
        for(long long i=0;i<n;i++){
            sum+=4*i;
           
        }
        return sum;
    }
};