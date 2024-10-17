class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
 int n= numCourses;
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
reverse(ans.begin(),ans.end());
       if (ans.size()==n){return ans;}
       else ans.clear();
        return ans;


    }
};