class Solution {
public:
bool isVowel(char &c){
        return (c == 'a'|| c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}
    bool halvesAreAlike(string s) {
        int n= s.size();
        int mid= n/2;
        int i=0, j= mid;
        int countL= 0;
        int countR= 0;

        while(i<n/2 and j<n){
            if(isVowel(s[i]))countL++;
            if(isVowel(s[j]))countR++;

            i++;
            j++;

        }

        return countL== countR;



    }
};