class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows= mat.size();
        int cols = mat[0].size();

        vector<vector<int>>dist(rows,vector<int>(cols,INT_MAX));
        queue<pair<int,int>>q;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            auto [x,y]= q.front();
            q.pop();

             for (auto dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && dist[newX][newY] > dist[x][y] + 1) {
                     dist[newX][newY] = dist[x][y] + 1;
                    q.push({newX, newY});
            }}
        }
 return dist;
    }
};