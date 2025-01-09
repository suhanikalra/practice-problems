class Solution {
public:
int solve(int i,int j, string s){
while(i>=0 and j<s.size() and s[i]==s[j]){i--;j++;}
return (j-i)/2;

}
    int countSubstrings(string s) {
        int odd=0,even=0;
        for (int i=0;i<s.size();i++){
             odd= odd+solve(i,i,s);
             even= even+solve(i,i+1,s);
        }
        return odd+even;
    }
};