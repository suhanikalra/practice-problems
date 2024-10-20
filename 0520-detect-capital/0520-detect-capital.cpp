class Solution {
public:
    bool allcaps(string word){
        for (auto c:word){
            if((c<'A') || (c>'Z')){
                return false;
            }
           
        }
         return true;
    }

    bool allsmall(string word){
        for (auto c:word){
            if((c<'a') || (c>'z')){
                return false;
            }
           
        }
         return true;
    }
    bool detectCapitalUse(string word) {
        return (allcaps(word)) || allsmall(word) || allsmall(word.substr(1));        
    }
};