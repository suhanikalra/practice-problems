class Solution {
public:
void remove(string &s, string part){
    //base
    if( s.find(part)== string::npos)return;

    //ek case ka solution
    if( s.find(part)!= string::npos)s.erase(s.find(part),part.length());
   remove(s,part);


}
    string removeOccurrences(string s, string part) {
        remove(s,part);
        return s;

    }
};