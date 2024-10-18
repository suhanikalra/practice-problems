#define ll long long
#define pll pair<ll,ll>
class Solution {
public:
   int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        //undiricted graph weighted toh dijekstra lagega
        vector<vector<pll>>graph(n);
        for(auto road:roads){
           ll u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});}
        return dijkstra(graph,n,0);
    }


    int dijkstra(const vector<vector<pll>>& graph, int n, int src) {
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        dist[src]=0;
        ways[src]=1;
        priority_queue<pll, vector<pll>, greater<>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto ele= pq.top();
            auto d= ele.first;
            auto u = ele.second;
            pq.pop();
            for(auto [v,t]: graph[u]){
                if (dist[v] > d + t) {
                    dist[v] = d + t;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                } else if (dist[v] == d + t) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }



        }
            } return ways[n-1];
    }
};