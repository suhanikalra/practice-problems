class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>m1,m2;
        for(int i=0;i<s.length();i++){

            if(m1[s[i]]==NULL && m2[t[i]]==NULL){
                m1[s[i]]=t[i];  
                m2[t[i]]=s[i];  
            }
           
            else if(m1[s[i]]!=t[i] || m2[t[i]]!=s[i]){
                return false;
            }
        }   
        return true;
    }
};