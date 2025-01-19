class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans=1;
        for(auto k: derived){
            ans=ans^k;
        }
        if(ans==1)return true;
        return false;
    }
};