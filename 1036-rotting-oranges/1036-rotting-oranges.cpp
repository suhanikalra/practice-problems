class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows= grid.size();
        int cols= grid[0].size();

        queue<pair<int,int>>rottenQueue;
        int freshOranges = 0;

        for(int i=0;i<rows;i++){
            for (int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    rottenQueue.push({i,j});}
                else if (grid[i][j]==1)freshOranges++;
                
            }
        }

        if (freshOranges==0)return 0;

        int time= -1;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 4-directional movements

        while(!rottenQueue.empty()){
            time++;
            int size= rottenQueue.size();

            for(int i=0;i<size;i++){
                pair<int, int> rotten = rottenQueue.front();
                rottenQueue.pop();

                for (auto dir : directions) {
                    int newRow = rotten.first + dir.first;
                    int newCol = rotten.second + dir.second;

                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
grid[newRow][newCol] = 2; // Rot the fresh orange
                        freshOranges--; // Decrease fresh orange count
                        rottenQueue.push({newRow, newCol});
            }
        }}}

return freshOranges == 0 ? time : -1;
    }
};

