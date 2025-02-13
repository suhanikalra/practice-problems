class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        vector<bool>vis(rooms.size(),false);
        vis[0]= true;
        for(auto k: rooms[0]){
            vis[k]=true;
            q.push(k);
        }
        
        while(!q.empty()){
            int p= q.front();
            q.pop();
            for(auto k: rooms[p]){
                if(vis[k]==true)continue;
                vis[k]=true;
                q.push(k);

            }
        }
        for(auto k: vis){
            if(k==false)return false;
        }
        return true;
    }
};