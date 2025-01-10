class Solution {
public:
    string reverseOnlyLetters(string s) {
        int start=0;
        int end= s.size()-1;
        while(start<=end){
            if(isalpha(s[start]) and isalpha(s[end])){swap(s[start],s[end]);end--;start++;}
            else if(!isalpha(s[start]))start++;
            else end--;

        }
        return s;
        
    }
};