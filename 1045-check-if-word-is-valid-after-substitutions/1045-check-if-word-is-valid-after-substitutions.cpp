class Solution {
public:
    bool isValid(string st) {
      
        while(st.find("abc")!=string::npos){
            if(st.find("abc")!=string::npos)st.erase(st.find("abc"),3);
        }
        return st.size()==0;
    }
};