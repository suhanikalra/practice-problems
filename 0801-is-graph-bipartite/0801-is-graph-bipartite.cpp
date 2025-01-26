class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),0);
        queue<int>q;
        for(int i=0;i<graph.size();i++){
            if(color[i] == 0) {
              
               color[i] = 1;
               queue<int> q;
               q.push(i);
               
               while(!q.empty()) {
                   int ele = q.front();
                   q.pop();
                   for(auto child: graph[ele]){
                    if(color[child]==0){
                        color[child]= -color[ele];
                        q.push(child);
                    }
                    else if( color[child]==color[ele])return false;


                   }
                }
            }
        }
        return true;
        
    }
};