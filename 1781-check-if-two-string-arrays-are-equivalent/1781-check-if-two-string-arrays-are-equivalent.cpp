class Solution {
public:

    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str="", st="";
        for(auto ch: word1){
            str += ch;
        }
        for(auto c: word2){
           st += c;
    }
    if(st==str){ return true;}
    return false;}

};