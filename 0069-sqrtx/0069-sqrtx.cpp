class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
       int start=1;int end= x;int ans=0;
       while(start<=end){
        long long mid= (end-start)/2+start;
        if(mid*mid==x)return mid;
        else if(mid*mid>x) end= mid-1;
        else {ans= mid;start= mid+1;}
       }
       return ans;
    }
};