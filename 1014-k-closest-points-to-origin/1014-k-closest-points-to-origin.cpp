class Solution {
public:
int dist(vector<int>d){
int distance= d[0]*d[0]+ d[1]*d[1];
return distance;
}
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        if(points.size()<k)return {};
                    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minheap;

    for(auto k: points){
        int d=dist(k);
        minheap.push({d,{k[0],k[1]}});
    }
    while(k--){
        auto ele= minheap.top();
        ans.push_back({ele.second.first,ele.second.second});
        minheap.pop();
    }
    return ans;
    }
};