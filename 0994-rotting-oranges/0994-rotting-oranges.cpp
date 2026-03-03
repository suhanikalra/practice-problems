class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;int fresh=0;int count=0;
       for( int i= 0 ;i<grid.size();i++){
        for( int j= 0;j<grid[0].size();j++){
            if(grid[i][j]==1)fresh++;
            if(grid[i][j]==2)q.push({i,j});
        }
       } 
       if( fresh==0)return 0;
       int dx[]={1,-1,0,0};
       int dy[]={0,0,-1,1};

       while( !q.empty()){
        int size= q.size();
        bool flag= false;
        for(int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
        
        for( int i=0;i<4;i++){
            auto newx= x+dx[i];
            auto newy= y+dy[i];

            if(newx>=0 and newy>=0 and newx< grid.size() and newy< grid[0].size() and grid[newx][newy]==1){
                grid[newx][newy]=2;
                q.push({newx,newy});
                fresh--;
                flag= true;
            }
            
        }
        }
        if(flag)count++;

        
       }
       if(fresh==0)return count;
       return -1;


    }
};