class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>losscount;
        unordered_map<int,int>wincount;
        for(auto k : matches){
            losscount[k[1]]++;
            wincount[k[0]]++;
        }
        vector<int>noloss;vector<int>oneloss;
        for(auto k: wincount){
            if(losscount.find(k.first)==losscount.end()) noloss.push_back(k.first);

        }
        for(auto k: losscount){if(k.second==1) oneloss.push_back(k.first);}
    
   vector< vector<int>>a;
   sort(noloss.begin(),noloss.end());
   sort(oneloss.begin(),oneloss.end());
    a.push_back(noloss);
     a.push_back(oneloss);
     
    return a;
    }
};