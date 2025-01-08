class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;bool flag = false;
        int count=0,maxi=0;
        for(auto k: s){
            mp[k]++;
        }
        for(auto k: mp ){
            if(k.second%2==0)count+=k.second;
            else if(k.second%2==1) {
                count+=k.second-1;
                flag=true;
            }

        }
        if(flag==true)count+=1;
        return count;
    }
};