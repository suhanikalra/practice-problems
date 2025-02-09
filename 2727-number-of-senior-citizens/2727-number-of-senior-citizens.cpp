class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(auto k: details){
            auto p = k.substr(11, 2);
            if(stoi(p)>60)count++;
        }return count;
    }
};