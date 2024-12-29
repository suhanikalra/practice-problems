class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
       int start=0;int end=x;int ans=1;
       while(start<=end){
        int mid= (end-start)/2+start;
        if((long long)mid*mid==x)return ans= mid;
        else if((long long)mid*mid>x) end=mid-1;
        else {ans=mid;start=mid+1;}
       } 
       return start-1;
    }
};