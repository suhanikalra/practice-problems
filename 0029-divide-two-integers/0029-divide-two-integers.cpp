class Solution {
public:
    int divide(int dividend, int divisor) {
      
        

       
        bool isNegative = (dividend < 0) ^ (divisor < 0);
if (dividend == INT_MIN && abs(divisor) == 1) return isNegative ? INT_MIN : INT_MAX;
       if(divisor==1)  return  dividend;
              if(divisor== -1)  return  -dividend;


      
        unsigned int absDividend = abs(dividend);
        unsigned int absDivisor = abs(divisor);
        
        int count = 0;
        while (absDividend >= absDivisor) {
            absDividend -= absDivisor;
            count++;
        }

        return isNegative ? -count : count;
    }
};
