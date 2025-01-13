class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0; bool flag=true;
         for(int j= 0;j<words.size();j++){
        for(int i= 0;i<pref.size();i++){

            if(words[j][i]!=pref[i]){flag=false;break;}

        }
        if(flag==true)count++;flag=true;}
        return count;
    }
};