class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int>q; 
        int n= graph.size();
        vector<int>color(n),vis(n,-1);

        for( int i=0;i<n;i++){
            if(vis[i] != -1) continue;
            q.push(i);color[i]=1;

            while(!q.empty()){
                auto ele= q.front();
                q.pop();
                vis[ele]=1;
                for( auto child: graph[ele]){
                    if(vis[child]==-1 ){
                        vis[child]=1;
                        color[child]= 1-color[ele];q.push(child);
                    }
                    if ( vis[child]==1 and color[child]==color[ele])return false;
                }
                
            }
        }
        return true;
    }
};