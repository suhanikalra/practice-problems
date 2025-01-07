class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";int count=1;
        s.push_back(chars[0]);
        for(auto i=1;i<chars.size();i++){
            if(chars[i]==chars[i-1]){count++;}
            else if(chars[i]!=chars[i-1]){if(count>1){ s=s+to_string(count);}
            s=s+chars[i];count=1;}
            
        }
        if(count>1)s=s+to_string(count);
        chars.clear();
        for(char k : s) {
            chars.push_back(k); 
        }
        

        return s.size();
        
    }
};