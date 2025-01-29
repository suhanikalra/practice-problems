class Solution {
public:
    bool isHappy(int n) {
       
        while(n>0){
            if(n==1)return true;
            int num=n;
             int sum=0;
            while(num>0){
           
            sum+= (num%10)*(num%10);
             num= num/10;}
             n=sum;
             if(n==4)return false;
        }
       return false;
    }
};