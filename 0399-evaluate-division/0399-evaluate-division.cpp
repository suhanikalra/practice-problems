class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> g;
        int n = equations.size();
        for(int i=0;i<n;i++){
            string a = equations[i][0], b = equations[i][1];
            double v = values[i];
            g[a].push_back({b, v});
            g[b].push_back({a, 1.0/v});
        }

        vector<double> ans;
        ans.reserve(queries.size());

        for(auto &q: queries){
            string s = q[0], t = q[1];
            if(!g.count(s) || !g.count(t)){
                ans.push_back(-1.0);
                continue;
            }
            if(s==t){
                ans.push_back(1.0);
                continue;
            }

            unordered_set<string> vis;
            queue<pair<string,double>> qu;
            qu.push({s, 1.0});
            vis.insert(s);
            double res = -1.0;

            while(!qu.empty()){
                auto [u, val] = qu.front();
                qu.pop();
                if(u==t){
                    res = val;
                    break;
                }
                for(auto &e: g[u]){
                    string v = e.first;
                    double w = e.second;
                    if(!vis.count(v)){
                        vis.insert(v);
                        qu.push({v, val*w});
                    }
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};
