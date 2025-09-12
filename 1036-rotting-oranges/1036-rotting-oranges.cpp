class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>,int>> q; 
        int freshCount = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        int time = 0;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty()){
            auto ele = q.front(); q.pop();
            int x = ele.first.first;
            int y = ele.first.second;
            int t = ele.second;
            time = max(time, t);

            for(int k=0; k<4; k++){
                int newx = x + dx[k];
                int newy = y + dy[k];
                if(newx>=0 && newy>=0 && newx<m && newy<n && grid[newx][newy]==1){
                    grid[newx][newy] = 2;
                    freshCount--;
                    q.push({{newx,newy}, t+1});
                }
            }
        }

        return freshCount == 0 ? time : -1;
    }
};
