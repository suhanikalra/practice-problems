class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows= grid.size();
        int columns= grid[0].size();
        int perimeter= 0;

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int,int>>q;

         for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j] == 1) {
                    
                    q.push({i, j});
                    grid[i][j] = -1; 
                    break;
                }
            }if (!q.empty()) break; }

            while(!q.empty()){
                auto [x,y]= q.front();
                q.pop();

                for(auto &dir: directions){
                    int nx =x +dir.first;
                    int ny= y+ dir.second;

                    if (nx < 0 || nx >= rows || ny < 0 || ny >= columns || grid[nx][ny] == 0) {
                    perimeter++;}
                    else if (grid[nx][ny] == 1) {
                    q.push({nx, ny});
                    grid[nx][ny] = -1;  // Mark as visited
                }
            }
        }
        
        return perimeter;
    }
};