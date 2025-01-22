class Solution {
public:
    int lengthOfLastWord(string s) {
        int size= s.size();int i=0;
        for( i= size-1;i>=0;i--){
            if(s[i]==' ')continue;
            else break;

        }int length=0;
        for(int j=0;j<i+1;j++){
            if(s[j]==' ')length=0;
            else length++;
        }
        return length;
    }
};