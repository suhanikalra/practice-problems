class Solution {
public:
    int dfs(vector<vector<pair<int, int>>>& graph,vector<bool> &visited, int start, int currWeight,
            int signalSpeed) {
        
        int totalValue=0;
        visited[start] = true;
        if(currWeight%signalSpeed==0)totalValue++;
        for (auto child : graph[start]) {

            int node = child.first;
            int wt = child.second;
            if(visited[node]==false)
            {
                    totalValue +=
                        dfs(graph, visited, child.first,
                            currWeight + child.second, signalSpeed);
            }

        }
        return totalValue;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges,
                                               int signalSpeed) {


        int n = edges.size()+1; //edges+1=node

        vector<vector<pair<int, int>>> graph(n);

        for (auto x : edges) {
            graph[x[0]].push_back({x[1], x[2]});
            graph[x[1]].push_back({x[0], x[2]});
        }
   
        vector<int> ans(n,0);
        for (int i = 0; i < n; i++) {

            vector<bool> visited(n,false);
            vector<int> cnt; //will give tle if we predecleare size 
            visited[i]=true;

            if(graph[i].size()<2)continue;

            for(auto child : graph[i])
            {
                int node = child.first;
                int currWeight = child.second;

                int currValue=dfs(graph,visited, node, currWeight, signalSpeed);
                cnt.push_back(currValue);
            }

            int total=0;
            for(int k=0;k<cnt.size();k++)
            {
                for( int j=k+1;j<cnt.size();j++)
                {
                    total=total+ cnt[k]*cnt[j];
                }
            }

            ans[i]=total;

        }

        return ans;
    }
};