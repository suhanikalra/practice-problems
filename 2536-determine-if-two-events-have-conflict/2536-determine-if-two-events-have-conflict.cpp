class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if(event1[0]<event2[0] and event2[0]<=event1[1])return true;
        if(event2[0]<event1[0] and event1[0]<=event2[1])return true;
        if(event2[0]==event1[0] || event1[0]==event2[1])return true;
        
        return false;
    }
};