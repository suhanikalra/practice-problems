class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        if(image[sr][sc] == color) return image;
        int orignal= image[sr][sc];
        image[sr][sc]=color;
        q.push({sr,sc});
        int dx[]={1,-1,0,0};
        int dy[]= {0,0,1,-1};
        while(!q.empty()){
            auto ele= q.front();
            int x= ele.first;
            int y= ele.second;
            q.pop();
            
            for(int i=0;i<4;i++){
                auto newx= x+dx[i];
                auto newy= y+dy[i];
                if(newx>=0 and newy>=0 and newx<image.size() and newy<image[0].size() and image[newx][newy]==orignal){
                    image[newx][newy]=color;
                    q.push({newx,newy});
                }
            }
        }
        return image;
    }
};