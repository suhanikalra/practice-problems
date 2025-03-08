class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;int fresh=0;int time=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2)q.push({{i,j},0});
                if(grid[i][j]==1)fresh++;
            }
        }
        while(!q.empty()){
            auto ele= q.front();
            int x= ele.first.first;
            int y= ele.first.second;
            int dist= ele.second;
            q.pop();
            int dx[]= {1,-1,0,0};
            int dy[]= {0,0,-1,1};
            for(int i=0;i<4;i++){
if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < grid.size() && y + dy[i] < grid[0].size() && grid[x + dx[i]][y + dy[i]] == 1){
                    q.push({{x+dx[i],y+dy[i]},dist+1});
                    cout<<dist+1;grid[x+dx[i]][y+dy[i]]=2;
                    time= max(dist+1,time); fresh--;
                }
            }

        }if(fresh==0)return time;
        return -1;
        
    }
};