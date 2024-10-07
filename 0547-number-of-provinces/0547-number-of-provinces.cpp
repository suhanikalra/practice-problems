class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(n,false);
        int provinceCount= 0;

        //iterate through each city
        for(int i=0;i<n;i++){
            if(!visited[i]){
                provinceCount++;

                //bfs from city i
                queue<int> q;
                q.push(i);
                visited[i]= true;

                while (!q.empty()) {
                    int city = q.front();
                    q.pop();
                //visit neighbours
                for(int j=0;j<n;j++){
                    if(isConnected[city][j]==1 && !visited[j]){
                        q.push(j);
                        visited[j]=true;

                    }}
                }       
                
                
                
                
                 }
        }return provinceCount;
    }
};