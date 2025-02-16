class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
        string a= goal+goal;
        if(a.find(s)!=string::npos)return true;
        return false;
    }
};