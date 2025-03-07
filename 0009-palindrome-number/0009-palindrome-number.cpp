class Solution {
public:
long long reverse(int n){
    long long num=0;
    while(n>0){
        int digit= n%10;
        num= num*10+digit;
        n=n/10;
    }
    return num;
}
    bool isPalindrome(int x) {
        if(x<0)return false;
        int t= x;
        t=reverse(t);
        if(t!=x)
        return false;

        return true;

        
    }
};