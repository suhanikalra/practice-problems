class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>vis(rooms.size(),-1);
        int n=rooms.size();
        queue<int>q;int count=1;vis[0]=1;
        for(auto k: rooms[0]){
        q.push(k);vis[k]=1;count++;
        }
        while(!q.empty()){
            int ele= q.front();
            q.pop();
            for(auto k: rooms[ele] ){
                if(vis[k]==-1){
                    vis[k]=1; q.push(k);count++;
                }

            }
            


        }
        return count==n;
    }
};