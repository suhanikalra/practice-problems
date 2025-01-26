class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0; 
         for(auto k: words){
            if(k.find(pref)!= string::npos){
                if(k.substr(0,pref.size())==pref)count++;
            }
         }
         return count;
    }
};