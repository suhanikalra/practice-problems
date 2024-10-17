class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
       vector<int> adj[n];
       vector<int> indegree(n,0);
       vector<int>ans;

       for(auto x: prerequisites){
        adj[x[0]].push_back(x[1]);
        indegree[x[1]]++;
       }

       queue<int> q;
       for(int i=0;i<n;i++){
        if(indegree[i]==0){q.push(i);}
       }

       while(!q.empty()){
        auto ele= q.front();
        ans.push_back(ele);
        q.pop();
        
        for(auto p:adj[ele]){
            indegree[p]--;
            if(indegree[p]==0){
                q.push(p);

            }
        }
       }

       return (ans.size()==n);


    }
};