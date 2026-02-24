class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=0,size=0;string ans="";
        for( auto c:s){
            if( c=='1')ones++;
            size++;
        }
        while(size and  ones>1){
            ans+='1';size--;ones--;
        }
        while(size>1){
            ans+='0';size--;
        }
        ans+='1';
        return ans;
    }
};