class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        
         int n = adj.size();

        queue<int>q;
        vector<int>indegree(n,0);int i=0;
        for(auto a: prerequisites){
            adj[a[1]].push_back(a[0]);
            indegree[a[0]]++;
            } 

        for(int i=0;i<n;i++){
                if(indegree[i]==0)q.push(i);
            }
            vector<int>ans;

        while(!q.empty()){
            auto ele= q.front();q.pop();
            ans.push_back(ele);
            for(auto nbr: adj[ele]){
                indegree[nbr]--;
                if(indegree[nbr]==0)q.push(nbr);
            }


        }
        return ans.size()==n;
        



    }
};