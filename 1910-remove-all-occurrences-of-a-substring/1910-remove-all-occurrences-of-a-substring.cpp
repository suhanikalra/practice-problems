class Solution {
public:
    string removeOccurrences(string s, string part) {
        if (s.find(part) == string::npos)
            return s;
        int pos = s.find(part);
        if (pos != string::npos) {
            s.erase(pos, part.size());
           
        }
         return removeOccurrences(s,part); 
    }
};