class Solution {
public:
    int countReachableNodes(int root, int check, int signalSpeed, vector<vector<pair<int, int> > > &adj, int distance) {
        int count = 0;

        if (!(distance%signalSpeed)) count++;
   
        for (pair<int, int> p : adj[check]) {
            if (p.first == root) continue;
            else {
                count += countReachableNodes(check, p.first, signalSpeed, adj, distance + p.second);
            }
        }
        return count;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        
        unordered_set<int> s;
        for (vector<int> v : edges) {
            int n1 = v[0];
            int n2 = v[1];
            if (s.find(n1) == s.end()) s.insert(n1);
            if (s.find(n2) == s.end()) s.insert(n2);
        }
        int n = s.size();
        vector<vector<pair<int, int> > > adj(n);
        for (vector<int> v : edges) {
            int n1 = v[0];
            int n2 = v[1];
            int w = v[2];
            adj[n1].push_back({n2, w});
            adj[n2].push_back({n1, w});
        }
      
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
          
            if (adj[i].size() < 2)  res[i] = 0;
            else {
               
                vector<int> reachables;
                for (pair<int, int> p : adj[i]) {
              
                    int reachable_nodes = countReachableNodes(i, p.first, signalSpeed, adj, p.second);
                    if (reachable_nodes > 0 ) {
                        reachables.push_back(reachable_nodes);
                    }
                }
                int sum = 0;
                int m = reachables.size();
                for (int i = 0; i < m; i++) {
                    for (int j = i+1; j < m; j++) {
                        sum += reachables[i] * reachables[j];
                    }
                }
                res[i] = sum;
            }
        }
        return res;
    }
};