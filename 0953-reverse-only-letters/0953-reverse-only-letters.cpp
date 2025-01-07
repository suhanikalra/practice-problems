class Solution {
public:
    string reverseOnlyLetters(string s) {
        int start=0;
        int n= s.size();
        int end= n-1;
        while(start<=end){
            if(isalpha(s[start]) and isalpha(s[end])){swap(s[start],s[end]);start++;end--;}
              else if(isalpha(s[start])==false)start++;
              else if(isalpha(s[end])==false) end--;
        }
        return s;
        
    }
};