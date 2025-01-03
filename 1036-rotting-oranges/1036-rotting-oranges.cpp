class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;int time=0;
int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if (grid[i][j] == 1) {
                    fresh++; }
                if(grid[i][j]==2){q.push({{i,j},0});}
            }
        }
        if (fresh == 0) return 0;
    int dx[]= {-1,1,0,0};
    int dy[]={0,0,1,-1};


        while(!q.empty()){
            auto ele= q.front();
            int x= ele.first.first;
            int y= ele.first.second;
              int distance= ele.second;
             if(fresh==0)break;
            q.pop();
            for(int i=0;i<4;i++){
                int newx= x+dx[i];
                int newy= y+dy[i];
                if(newx>=0 and newy>=0 and newx<grid.size() and newy<grid[0].size() and grid[newx][newy]==1){
                    grid[newx][newy]=2;
                     
                q.push({{newx,newy},distance+1});
                time= max(time,distance+1); 
                    
                    fresh--;
                }
            }
        }
return (fresh == 0) ? time : -1;        
    }
};