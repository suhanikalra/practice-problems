class Solution {
public:
    bool canPermutePalindrome(string s) {int odd=0;
        unordered_map<char,int>mp;
        for(auto k: s){
            mp[k]++;
        }
        for(auto &[x,y]: mp){
            if(y%2==1)odd++;
        }
        return odd<=1;
    }
};