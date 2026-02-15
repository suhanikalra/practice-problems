class Solution {
public:
    int getSum(int a, int b) {
        int ans=1;
        int carry=1;
        while(carry!=0){
            ans= a^b;
            carry= (a&b)<<1;
            a= ans;
            b= carry;
        }
        return ans;
    }
};