class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int>mp;int count=0;
        int x=arr.size()/4;
        for(auto k : arr){
            mp[k]++;
            count++;
            if(mp[k]>x)break;

        }
        for(auto k:mp){
            if((k.second*100)/count>=25)return k.first;
        }
        return -1;
    }
};