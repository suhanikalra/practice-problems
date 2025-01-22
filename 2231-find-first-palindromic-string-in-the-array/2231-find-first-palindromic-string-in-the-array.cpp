class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto k: words){
            auto p= k;
            reverse(p.begin(),p.end());
            if(p==k)return k;
        }
        return "";
        
    }
};