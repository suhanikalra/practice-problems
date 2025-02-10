class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
    queue<pair<pair<int,int>, int>> q; 
    for(int i=0;i<rooms.size();i++){
        for(int j=0;j<rooms[0].size();j++){
            if(rooms[i][j]==0)
            q.push({{i,j},0});
        }
    } 

    while(!q.empty()){
        auto ele= q.front();
        q.pop();
        int x= ele.first.first;
        int y= ele.first.second;
        int distance= ele.second;

        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};

        for(int i=0;i<4;i++){
            auto nx= x+dx[i];
            auto ny= y+dy[i];
            if(nx>=0 and nx<rooms.size() and ny>=0 and ny<rooms[0].size() ){
                if(rooms[nx][ny]==2147483647){
                    rooms[nx][ny]=distance+1;
                    q.push({{nx,ny},distance+1});

                }
                
            }
        }
    } return;     
    }
};