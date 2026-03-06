class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for( int i=0;i<words.size();i++){
            auto word= words[i];
            bool flag= true;
            if(word.find(pref)==0)count++;
        }
        return count;

    }
};