class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto ind= upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        if(ind==letters.size())return letters[0];
        return letters[ind];
        
    }
};