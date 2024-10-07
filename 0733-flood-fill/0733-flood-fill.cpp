class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row= image.size();
        int cols= image[0].size();
        int orignalColor= image[sr][sc];

        if(orignalColor==color)return image;

        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            auto[x,y]= q.front();
            q.pop();

            for (auto dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                if (newX >= 0 && newX < row && newY >= 0 && newY < cols && image[newX][newY] == orignalColor) {
                    image[newX][newY]= color;
                    q.push({newX,newY});
                }
        }}
        return image;

    }
};