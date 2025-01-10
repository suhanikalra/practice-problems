class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m= grid.size();int n= grid[0].size();
        queue<pair<pair<int,int>,int>>q;int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)fresh++;
                if(grid[i][j]==2)q.push({{i,j},0});
            }
        }
        int time=0;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};
         if(fresh == 0) return 0;
        
       
        while(!q.empty() && fresh > 0) {
            auto size= q.size();
            
            while(size--){
                if(fresh==0)break;
                auto ele= q.front();
                int x= ele.first.first;
                int y= ele.first.second;
                int distance= ele.second;
                q.pop();
                for(int i=0;i<4;i++){
                    int newx= x+dx[i];
                    int newy= y+dy[i];
                    if(newx>=0 and newy>= 0 and newx<m and newy< n and grid[newx][newy]==1){
                        grid[newx][newy]=2;
                        q.push({{newx,newy},distance+1});
                        fresh--;
                         time= max(time,distance+1);
                       

                    }

                }
            }
        }
        if (fresh == 0)
            return time;
        return -1;
        
    }
};