class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp1;
        for(auto k: s){
            mp1[k]++;
        }
        int count=0;bool flag=false;
        for(auto k: mp1){
            if(k.second%2==0){count+=k.second;}
            else {flag=true;count+=k.second-1;}
        }
        if(flag==true)return count+1;
        return count;

        
    }
};