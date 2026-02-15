class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
         vector<vector<int>>adjList(n);vector<int>indegree(n,0);
         for(auto e: prerequisites){
            auto x=e[0];auto y=e[1];
            adjList[y].push_back(x);
            indegree[x]++;
         }
         queue<int>q;
         for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
         }
vector<int>ans;
         while(!q.empty()){
            auto ele= q.front();
            q.pop(); ans.push_back(ele);
            for( auto nbr: adjList[ele]){
                indegree[nbr]--;
                if(indegree[nbr]==0){q.push(nbr);}
            }
         }
    

         return ans.size()==n;
         
    }
};