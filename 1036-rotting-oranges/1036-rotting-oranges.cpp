class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<pair<int, int>, int>> q;
    int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)fresh++;
                if(grid[i][j]==2)q.push({{i,j},0});
            }
        }
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int time=0;
        while(!q.empty()){
            
            
                auto ele= q.front();
                q.pop();
                int x= ele.first.first;
                int y= ele.first.second;
                for(int i=0;i<4;i++){
                    int newx=x+dx[i];
                    int newy= y+dy[i];
                    int dist=ele.second;
                    if(newx>=0 and newy>=0 and newx<grid.size() and newy<grid[0].size() and grid[newx][newy]==1){grid[newx][newy]=2;
                    time=max(time,dist+1);
                    q.push({{newx,newy},dist+1});
                    fresh--;

                    
                }

            }
        }
        if(fresh==0)return time;
        return -1;
    }



};