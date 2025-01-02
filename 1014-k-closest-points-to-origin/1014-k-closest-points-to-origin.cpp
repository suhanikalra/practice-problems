class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,pair<int,int>>>p;
        for(auto k: points){
            int d=k[0]*k[0]+k[1]*k[1];
           p.push_back({d,{k[0],k[1]}});
          
           }
            sort(p.begin(),p.end());
            vector<vector<int>>ans;
           for(int i=0;i<k;i++){
            ans.push_back({p[i].second.first,p[i].second.second});
        }
        return ans;
    }
};