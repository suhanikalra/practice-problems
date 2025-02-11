class Solution {
public:
    string removeOccurrences(string s, string part) {
        if(s.find(part)==string::npos)return s;

        auto k= s.find(part);
        s = s.substr(0, k) + s.substr(k + part.size());
        return removeOccurrences(s,part);
        
    }
};